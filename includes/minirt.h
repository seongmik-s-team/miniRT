/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:37:09 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/21 16:38:21 by jooahn           ###   ########.fr       */
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

typedef struct s_camera
{
	t_point3 origin; // 카메라의 좌표(카메라의 원점)
	t_vec3 ov;       // orientation vector (카메라의 방향벡터) [-1, 1]
	double fov;      // Field of view (시야각) [0, 180]
}						t_camera;

typedef struct s_light
{
	t_point3 point; // 빛의 좌표
	double ratio;   // 빛의 밝기 비율 [0.0, 1.0]
}						t_light;

typedef struct s_sphere
{
	t_point3 center; // 구의 중심 좌표
	double diameter; // 구의 반지름
	t_color3 color;  // RGB 색상 [0-1]
}						t_sphere;

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

typedef struct s_scene
{
	int					width;
	int					height;
	double aspect_ratio; // 종횡비 (스크린 가로 길이 / 세로 길이)
	t_ambient ambient;   // 주변광
	t_camera camera;     // 카메라
	t_list *light_list;  // 라이트 리스트
	t_list *object_list; // 오브젝트 리스트
}						t_scene;

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

/****************************** temp **********************************/
t_color3				new_color3(double x, double y, double z);
t_point3				new_point3(double x, double y, double z);
t_color3				to_color3(t_rgb rgb);

/*********************************** error ************************************/
void					pexit(const char *msg);

/*********************************** mlx **************************************/
void					mr_mlx_init(t_scene *t_scene);
int						key_hook(int keycode, t_mlx_ptrs *ptrs);
int						exit_hook(t_mlx_ptrs *ptrs);

/********************************** object ************************************/
t_object				*new_object(char **datas);
t_sphere				*new_sphere(char **datas);
t_plane					*new_plane(char **datas);
t_cylinder				*new_cylinder(char **datas);
t_bool					is_object(char *id);

/********************************** vector ************************************/

t_vec3					*new_vec3(double x, double y, double z);
t_vec3					*copy_vec3(t_vec3 *origin);

t_vec3					vadd(t_vec3 lv, t_vec3 rv);
t_vec3					vsub(t_vec3 lv, t_vec3 rv);
t_vec3					vdiv(t_vec3 v, double value);
t_vec3					vmult(t_vec3 v, double value);
double					vdot(t_vec3 lv, t_vec3 rv);
t_vec3					vcross(t_vec3 lv, t_vec3 rv);
double					vlen(t_vec3 v);
t_vec3					vunit(t_vec3 v);

#endif
