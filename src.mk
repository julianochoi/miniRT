SRC_FILES	=	minirt.c

SRC_FILES	+=	env/camera.c	\
				env/display.c	\
				env/img_list.c	\
				env/img.c		\
				env/init.c		\
				env/lights.c	\
				env/obj.c

SRC_FILES	+=	parse/parse_objs.c	\
				parse/parse_scene.c	\
				parse/parse_utils.c	\
				parse/parse_value.c	\
				parse/parsing.c

SRC_FILES	+=	render/hit_cylinder.c	\
				render/hit_plane.c		\
				render/hit_sphere.c		\
				render/hit_square.c		\
				render/hit_triangle.c	\
				render/render.c			\
				render/shader.c			\
				render/trace_light.c	\
				render/trace_objs.c		\
				render/trace_utils.c	\
				render/tracer.c

SRC_FILES	+=	util/bmp_padding.c	\
				util/bmp.c			\
				util/errors_exits.c \
				util/events.c

SRC_FILES	+=	debug/debug_env.c	\
				debug/debug_math.c	\
				debug/debug_objs.c	\
				debug/debug_prints.c