#include "../incls/mini_rt.h"

t_mlx	*get_mlx(void)
{
	static t_mlx	mlx;

	if (mlx.init != 1)
    {
        mlx.mlx = mlx_init();
		mlx.width = 1080;
		mlx.height = 1024;
      	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
		mlx.adr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.w_len, &mlx.endian);
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "mini_RT");
        mlx.init = 1;
    }
    return (&mlx);
}

void	init_rt(t_rt *rt)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	rt->height = 1080;
	rt->width = 1024;
	rt->img_ptr = mlx->img;
	rt->scene = init_scene();
}