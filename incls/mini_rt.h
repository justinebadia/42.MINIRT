#ifndef MINI_RT_H
# define MINI_RT_H

# include "color.h"
# include "event.h"
# include "parsing.h"
# include "scene.h"
# include "vector_3d.h"
# include "vector_array.h"
# include "../libft/libsrcs/libft.h"
# include "../libft/libsrcs/ft_printf.h"
# include "../libft/libsrcs/get_next_line.h"
# include "../libx/mlx.h"

# define ANGLE 3.6
# define STEP 0.5
# define YES 1
# define NONE 0
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_ROULETTE 3
# define ROULETTE_FORWARD 5
# define ROULETTE_BACKWARD 4
# define KEY_ESC 53
# define KEY_Q 12
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_R 15
# define KEY_T 17
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_PLUS_PETIT 43
# define KEY_PLUS_GRAND 47
# define KEY_L 37
# define X_AXIS 7
# define Y_AXIS 16
# define Z_AXIS 6
# define WIDTH	1080
# define HEIGHT 720
# define M_EPSILON 1e-8
# define M_INFINITY 1.0e30f

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*adr;
	int		width;
	int		height;
	int		init;
	int		bpp;
	int		endian;
	int		w_len;
}			t_mlx;

/*MLX_UTILS_C*/
int		key_event(int key, t_scene *scene);
int	click_close_window(void);
int	hook_collection(t_mlx *mlx, t_scene *scene);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
t_mlx	*get_mlx(void);

/*MOVEMENTS
MOVE_CAM_C*/
void	move_cam(int keycode, t_scene *scene);
void	remake_scene(t_scene *scene, t_mlx *mlx);

/*SHAPES
SPHERE_C*/
t_vec3	get_norm_sphere(t_scene *scene, t_vec3	hit_p);
t_vec3	get_hit_point(t_scene *scene, t_ray ray, double distance);
double	get_root(double disc, double b);
double	hit_sphere(void *sphere, t_vec3 cam, t_vec3 direction);
/*PLANE_C*/
double hit_plane(void *plan, t_vec3 ray_origin, t_vec3 ray_direction);
double	hit_cylinder(void *cylinder, t_vec3 ray_origin, t_vec3 ray_direction);
t_vec3	get_cyl_norm(t_vec3 hit_p, void *cyl);
double	check_cyl_root(t_vec3 ray_origin, t_vec3 ray_direction, t_shape *cyl, double disc, double b);


/*RAY_HIT
GET_COLOR_C*/
int		get_color(t_shape *obj, t_ray ray, t_scene *scene, double distance);
double	shadow_ray(t_vec3 hit_point, t_scene *scene, t_vec3 ray_dir);
t_vec3 get_reflect(t_vec3 norm, t_vec3 ray_dir);
double	spot_light(t_vec3 hit_point, t_scene *scene, t_vec3 norm);
double	spec_light(t_vec3 norm, t_vec3 dir, t_vec3 hit_point, t_scene *scene);
/*LIGHT_C*/
t_rgb	get_diffuse_lit(t_rgb obj, t_scene *scene);
t_rgb	get_spec_lit(t_rgb obj,	double ks);
t_rgb	get_ambient_lit(t_scene *scene, t_rgb obj);

/*MAIN_C*/
void	ray_tracing(t_scene *scene, int x, int y);
t_vec3	get_ray_dir(t_scene *scene, t_mlx *mlx, double u, double v);
void	make_scene(t_scene *scene);

#endif