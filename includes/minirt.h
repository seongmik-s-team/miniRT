/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:37:09 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/28 02:21:19 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define ESC_KEY 53
# define R_KEY 15
# define L_KEY 37

# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define EXIT_BUTTON 17

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

# define RGB_MAX 255.999
# define LITTLE 0.0000001

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;
typedef int				t_bool;

struct					s_vec3
{
	double				x;
	double				y;
	double				z;
};

typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

enum					e_object_type
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_object
{
	enum e_object_type	type;
	void				*obj;
}						t_object;

typedef struct s_sphere
{
	t_point3			center;
	double				diameter;
	t_color3			color;
}						t_sphere;

typedef struct s_recoder
{
	double				max_len;
	t_color3			color;
	t_point3			p;
	t_vec3				nv;
}						t_recoder;

typedef struct s_ray
{
	t_point3			origin;
	t_vec3				direction;
}						t_ray;

typedef struct s_camera
{
	t_point3			origin;
	t_vec3				ov;
	double				viewport_height;
	double				viewport_width;
	double				focal_length;
	t_vec3				horizontal;
	t_vec3				vertical;
	t_vec3				lower_left;
	double				fov;
}						t_camera;

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_mlx_ptrs
{
	void				*mlx;
	void				*win;
	t_data				data;
}						t_mlx_ptrs;

typedef struct s_ambient
{
	double				ratio;
	t_color3			color;
}						t_ambient;

typedef struct s_light
{
	t_point3			point;
	double				ratio;
}						t_light;

typedef struct s_scene
{
	t_mlx_ptrs			ptrs;
	int					width;
	int					height;
	double				aspect_ratio;
	t_camera			camera;
	t_ambient			ambient;
	t_light				light;
	t_list				*objs;
	t_recoder			rec;
}						t_scene;

typedef struct s_plane
{
	t_point3			center;
	t_vec3				axis;
	t_color3			color;
}						t_plane;

typedef struct s_circle
{
	t_point3			center;
	t_vec3				axis;
	double				radius;
}						t_circle;

typedef struct s_cylinder
{
	t_point3			center;
	t_vec3				axis;
	double				diameter;
	double				height;
	t_color3			color;
	t_circle			topcap;
	t_circle			botcap;
}						t_cylinder;

/********************************** parser ************************************/
void					parser(char *argv, t_scene *scene);

/******************************* add_to_scene *********************************/
void					add_to_scene(t_scene *scene, char **datas);

/****************************** parser_utils **********************************/
double					ft_strtod(const char *str);
int						get_type(char *id);
int						get_arr_size(char **p);
char					*get_trimmed_line(int fd);
t_vec3					str_to_vec3(char *str, char sep);
t_rgb					str_to_rgb(char *str, char sep);
t_bool					is_rgb(t_rgb rgb);
double					validate_ratio(double ratio);
t_vec3					validate_uvec(t_vec3 uvec);
double					validate_fov(double fov);

/********************************** utils *************************************/
t_point3				ray_at(t_ray ray, double t);
t_color3				cal_color3(t_scene *scene, t_color3 obj_color);

/*********************************** error ************************************/
void					pexit(const char *msg);

/*********************************** mlx **************************************/
void					mr_mlx_init(t_scene *scene);
int						key_hook(int keycode, t_scene *scene);
int						exit_hook(t_mlx_ptrs *ptrs);
void					mr_mlx_pixel_put(t_data *data, int x, int y, int color);
void					draw_screen_simple(t_scene *scene, t_mlx_ptrs *ptrs);
void					draw_screen(t_scene *scene, t_mlx_ptrs *ptrs);

/*********************************** hit **************************************/
t_bool					hit(t_scene *scene, t_node *objs, t_ray ray);
t_bool					type_hit(t_scene *scene, t_object *obj, t_ray ray);
t_bool					hit_sphere(t_scene *scene, t_sphere *sphere, t_ray ray);
t_point3				hit_spot(t_sphere *sphere, t_ray ray);
t_bool					just_hit(t_node *objs, t_ray ray, t_recoder *rec);
t_bool					just_type_hit(t_object *obj, t_ray ray, t_recoder *rec);
t_bool					just_hit_sphere(t_sphere *sphere, t_ray ray,
							t_recoder rec);
t_bool					hit_plane(t_scene *scene, t_plane *plane, t_ray ray);
t_bool					just_hit_plane(t_plane *plane, t_ray ray,
							t_recoder rec);
t_bool					hit_cylinder(t_scene *scene, t_cylinder *cy, t_ray ray);
t_bool					hit_cylinder_side(t_scene *scene, t_cylinder *cy,
							t_ray ray);
t_bool					hit_cylinder_cap(t_scene *scene, t_cylinder *cy,
							t_ray ray);
t_bool					just_hit_cylinder(t_cylinder *cy, t_ray ray,
							t_recoder *rec);
t_bool					just_hit_cylinder_side(t_cylinder *cy, t_ray ray,
							t_recoder *rec);
t_bool					just_hit_cylinder_cap(t_cylinder *cy, t_ray ray,
							t_recoder *rec);
t_bool					hit_circle(t_circle circle, t_ray ray, t_recoder *rec);
t_bool					just_hit_circle(t_circle circle, t_ray ray);

/*********************************** ray **************************************/
t_ray					ray_primary(t_camera cam, double x, double y);
int						ray_color(t_scene *scene, t_ray ray);

/********************************** color *************************************/
t_color3				new_color3(double x, double y, double z);
int						sky_color(t_ray ray);
t_rgb					to_rgb(t_color3 color);
int						to_hex(t_rgb rgb);
t_color3				to_color3(t_rgb rgb);

/********************************** object ************************************/
t_object				*new_object(char **datas);
void					del_object(void *obj);
t_plane					*new_plane(char **datas);
t_cylinder				*new_cylinder(char **datas);
t_circle				new_circle(t_vec3 axis, t_point3 center, double radius);
t_bool					is_object(char *id);

/********************************** sphere ************************************/
t_sphere				*new_sphere(char **datas);
t_bool					hit_sphere(t_scene *scene, t_sphere *sphere, t_ray ray);

/********************************** scene *************************************/
void					scene_init(t_scene *scene);
void					del_scene(t_scene *scene);

/********************************* ambient ************************************/
t_ambient				new_ambient(char **datas);

/********************************** camera ************************************/
t_camera				new_camera(t_scene *scene, char **datas);
t_camera				move_camera(t_scene *scene, t_point3 move);
t_camera				rotate_camera(t_scene *scene, t_vec3 ov);

/********************************** point *************************************/
t_point3				new_point3(double x, double y, double z);

/********************************* shadow *************************************/
t_color3				shadow(t_scene *scene, t_light light, t_point3 spot);

/********************************** light *************************************/
t_light					new_light(char **datas);
void					set_light(t_scene *scene, t_point3 set_point);
t_color3				lighting(t_light light, t_point3 spot, t_vec3 nv);

/********************************** vector ************************************/
t_vec3					new_vec3(double x, double y, double z);
t_vec3					copy_vec3(t_vec3 *origin);
t_vec3					vplus(t_vec3 lv, t_vec3 rv);
t_vec3					cplus(t_vec3 lv, t_vec3 rv);
t_vec3					vminus(t_vec3 lv, t_vec3 rv);
t_vec3					vdiv(t_vec3 v, double value);
t_vec3					vmult(t_vec3 v, double value);
t_vec3					cmult(t_vec3 lv, t_vec3 rv);
double					vdot(t_vec3 lv, t_vec3 rv);
t_vec3					vcross(t_vec3 lv, t_vec3 rv);
double					vlen(t_vec3 v);
t_vec3					vunit(t_vec3 v);

#endif
