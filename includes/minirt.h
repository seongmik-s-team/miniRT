/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:37:09 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/22 21:04:44 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define ESC_KEY 53
# define EXIT_BUTTON 17

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

# define RGB_MAX 255.999

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
	t_point3 center; // 구의 중심 좌표
	double diameter; // 구의 반지름
	t_color3 color;  // RGB 색상 [0-1]
}						t_sphere;

typedef struct s_recoder
{
	double				max_len;
	t_color3			color;
}						t_recoder;

typedef struct s_ray
{
	t_point3			origin;
	t_vec3				direction;
}						t_ray;

typedef struct s_camera
{
	t_point3 origin;        // 카메라의 좌표(카메라의 원점)
	t_vec3 ov;              // orientation vector (카메라가 바라보고 있는 방향을 나타내는 단위벡터)
	double viewport_height; // 뷰포트 높이
	double viewport_width;  // 뷰포트 너비
	double focal_length;    // 바라보는 시점의 평면과의 거리
	t_vec3 horizontal;      // 뷰포트의 수직 벡터 (0, 0, viewport_width)
	t_vec3 vertical;        // 뷰포트의 수평 벡터 (0, viewport_height, 0)
	t_vec3 lower_left;      // 뷰포트의 왼쪽 아래 점
	double fov;             // Field of view (시야각)
}						t_camera;

typedef struct s_mlx_ptrs
{
	void				*mlx;
	void				*win;
}						t_mlx_ptrs;

typedef struct s_ambient
{
	double ratio;   // 조명빛의 세기 비율 [0.0, 1.0]
	t_color3 color; // 조명색 (RGB) [0, 1]
}						t_ambient;

typedef struct s_light
{
	t_point3 point; // 빛의 좌표
	double ratio;   // 빛의 밝기 비율 [0.0, 1.0]
}						t_light;

typedef struct s_scene
{
	int					width;
	int					height;
	double aspect_ratio; // 종횡비 (스크린 가로 길이 / 세로 길이)
	t_camera camera;     // 카메라
	t_ambient ambient;   // 주변광
	t_light light;       // 라이트
	t_list *objs;        // 오브젝트 리스트
	t_recoder			rec;
}						t_scene;

typedef struct s_plane
{
	t_point3 center; // 평면의 중심 좌표
	t_vec3 axis;     // 평면의 방향 벡터 [-1,1]
	t_color3 color;  // RGB 색상 [0-1]
}						t_plane;

typedef struct s_cylinder
{
	t_point3 center; // 원기둥의 중심 좌표
	t_vec3 axis;     // 원기둥의 방향 벡터 [-1,1]
	double diameter; // 반지름
	double height;   // 높이
	t_color3 color;  // RGB 색상 [0-1]
}						t_cylinder;

/********************************** parser ************************************/
void					parser(char *argv, t_scene *scene);

/******************************* add_to_scene *********************************/
void					add_to_scene(t_scene *scene, char **datas);

/****************************** parser_utils **********************************/
double					ft_strtod(const char *str);
int						get_arr_size(char **p);
char					*get_trimmed_line(int fd);
t_vec3					str_to_vec3(char *str, char sep);
t_rgb					str_to_rgb(char *str, char sep);
t_point3				str_to_point3(char *str, char sep);
t_bool					is_rgb(t_rgb rgb);
double					validate_ratio(double ratio);
t_vec3					validate_uvec(t_vec3 uvec);
double					validate_fov(double fov);

/*********************************** error ************************************/
void					pexit(const char *msg);

/*********************************** mlx **************************************/
void					mr_mlx_init(t_scene *scene);
int						key_hook(int keycode, t_mlx_ptrs *ptrs);
int						exit_hook(t_mlx_ptrs *ptrs);

/*********************************** hit **************************************/
t_bool					hit(t_scene *scene, t_node *objs, t_ray ray);
t_bool					type_hit(t_scene *scene, t_object *obj, t_ray ray);
t_bool					hit_sphere(t_scene *scene, t_sphere *sphere, t_ray ray);
t_point3				hit_spot(t_sphere *sphere, t_ray ray);
t_bool					just_hit(void *me, t_node *objs, t_ray ray,
							t_recoder rec);
t_bool					just_type_hit(t_object *obj, t_ray ray, t_recoder rec);
t_bool					just_hit_sphere(t_sphere *sphere, t_ray ray,
							t_recoder rec);
t_bool					hit_plane(t_scene *scene, t_plane *plane, t_ray ray);
t_bool					just_hit_plane(t_plane *plane, t_ray ray,
							t_recoder rec);

/*********************************** ray **************************************/
t_ray					ray_primary(t_camera cam, double x, double y);
int						ray_color(t_scene *scene, t_ray ray);

/********************************** color *************************************/
t_color3				new_color3(double x, double y, double z);
t_rgb					to_rgb(t_color3 color);
int						to_hex(t_rgb rgb);
int						sky_color(t_ray ray);
t_color3				to_color3(t_rgb rgb);

/********************************** object ************************************/
t_object				*new_object(char **datas);
t_plane					*new_plane(char **datas);
t_cylinder				*new_cylinder(char **datas);
t_bool					is_object(char *id);

/********************************** sphere ************************************/
t_sphere				*new_sphere(char **datas);
t_bool					hit_sphere(t_scene *scene, t_sphere *sphere, t_ray ray);

/********************************** scene *************************************/
void					scene_init(t_scene *scene);

/********************************** point *************************************/
t_point3				new_point3(double x, double y, double z);

/********************************* shadow *************************************/
t_color3				shadow(t_scene *scene, void *me, t_light light,
							t_point3 spot);

/********************************** light *************************************/
t_light					new_light(char **datas);
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
