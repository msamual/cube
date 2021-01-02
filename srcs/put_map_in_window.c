#include "../includes/header.h"

void    print_first_step(t_ray *ray, t_all *all)
{
    t_vec   vec;
    t_vec   vec1;
    
    vec1.x = ray->dirx;
    vec1.y = ray->diry;
    vec.x = ray->x;
    vec.y = ray->y;
    if (ray->side_dist_x < ray->side_dist_y)
        add_vector1(&vec, &vec1, 1);
    else
    {
        add_vector1(&vec, &vec1, 1);
    }
    pixel_put(all, vec.x * SCALE, vec.y * SCALE, 0xbbbbbb);
    
}

void    print_ray(t_all *all, t_ray *ray)
{
    double x;
    double y;

    x = all->plr->pos->x;
    y = all->plr->pos->y;
    while (all->map[(int)y][(int)x] != '1')
    {
        x += ray->dirx / 30;
        y += ray->diry / 30;
        pixel_put(all, x * SCALE, y * SCALE, 0xbbbbbb);
    }
}

void    print_dir(t_all *all)
{
    double x;
    double y;

    x = all->plr->pos->x;
    y = all->plr->pos->y;
    while (all->map[(int)y][(int)x] != '1')
    {
        x += all->plr->dir->x / 30;
        y += all->plr->dir->y / 30;
        pixel_put(all, x * SCALE, y * SCALE, 0xbbbbbb);
    }
}

void    dda(t_ray *ray, t_all *all)
{
    int wall;

    wall = 0;
    while (!wall)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->mapx += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->mapy += ray->step_y;
            ray->side = 1;
        }
        if (all->map[ray->mapy][ray->mapx] == '1')
            wall = 1;
    }
}

void    first_step(t_ray *ray)
{
    if (ray->dirx > 0)
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->mapx + 1.0 - ray->x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = -1;
        ray->side_dist_x = (ray->x - ray->mapx) * ray->delta_dist_x;
    }
    if (ray->diry > 0)
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->mapy + 1.0 - ray->y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = -1;
        ray->side_dist_y = (ray->y - ray->mapy) * ray->delta_dist_y;
    }
}

void    delta(t_ray *ray)
{
    /*if (ray->diry == 0 || ray->dirx == 0)
    {
        if (!ray->diry)
        {
            ray->delta_dist_x = 0;
            ray->delta_dist_y = 1;
        }
        else
        {
            ray->delta_dist_x = 1;
            ray->delta_dist_y = 0;
        }
    }
    else
    {*/
        ray->delta_dist_x = sqrt(1 + (ray->diry * ray->diry) / (ray->dirx * ray->dirx));
        ray->delta_dist_y = sqrt(1 + (ray->dirx * ray->dirx) / (ray->diry * ray->diry));
   // }
    
}

void    perp(t_ray *ray)
{
    if (ray->side == 0)
        ray->perp = (ray->mapx - ray->x + (1 - ray->step_x) / 2) / ray->dirx;
    else
        ray->perp = (ray->mapy - ray->y + (1 - ray->step_y) / 2) / ray->diry;
     
}

void    ray(t_all *all, t_vec *dir)
{
    t_ray   ray;

    ray.x = all->plr->pos->x;
    ray.y = all->plr->pos->y;
    ray.mapx = (int)ray.x;
    ray.mapy = (int)ray.y;
    ray.side = 0;
    ray.dirx = dir->x;
    ray.diry = dir->y;
    delta(&ray);
    first_step(&ray);
    //print_first_step(&ray, all);
    //print_ray(all, &ray);
    dda(&ray, all);
    perp(&ray);
    printf("perp = %lf\n", ray.perp);
    //print_first_step(&ray, all);
}

void    draw_rays(t_all *all)
{
    int     i;
    t_vec   start;

    i = 0;
    sub_three(&start, all->plr->dir, all->plr->plane, 1);
    while (i < all->resolution->width)
    {
        ray(all, &start);
        add_vector(&start, all->plr->plane, all->resolution->width / 2);
        i++;
    }
    print_dir(all);
    //ray(all, all->plr->dir);
}

void    put_line(t_all *all, char *line, int y, int scl)
{
    int     x;
    int     sc;

    x = 0;
    sc = 0;
    while (line[x])
    {
        if (line[x] == '1')
            pixel_put(all, x * scl + sc, y, 0xffaaff);
        sc++;
        if (sc == scl)
        {
            x++;
            sc = 0;
        }
    }
}

int     put_map(t_all *all, int scl)
{
    int     y;
    int     sc;
    
    all->win->img = mlx_new_image(all->win->mlx, all->resolution->width,
                                        all->resolution->height);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bpp,
										&all->win->line_l, &all->win->en);
    y = 0;
    sc = 0;
    while (all->map[y])
    {
        put_line(all, all->map[y], y * scl + sc, scl);
        sc++;
        if (sc == scl)
        {
            y++;
            sc = 0;
        }
    }
    pixel_put(all, all->plr->pos->x * scl, all->plr->pos->y * scl, 0xbbbbbb);
    draw_rays(all);
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
    mlx_destroy_image(all->win->mlx, all->win->img);
    return (0);
}