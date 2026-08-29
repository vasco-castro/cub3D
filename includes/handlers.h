#ifndef HANDLERS_H
# define HANDLERS_H

# define CLOSE_KEY 17

# define MOVE_SPEED 3.0
# define ROT_SPEED 3.0

// TODO: Add mouse buttons and movement keys
# ifdef __APPLE__
#  define ESCAPE_KEY 53

#  define UP_KEY 126
#  define DOWN_KEY 125
#  define LEFT_KEY 123
#  define RIGHT_KEY 124

#  define W_KEY 13
#  define S_KEY 1
#  define A_KEY 0
#  define D_KEY 2

#  define L_SHIFT_KEY 257
# else
#  define ESCAPE_KEY 65307

#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363

#  define W_KEY 119
#  define S_KEY 115
#  define A_KEY 97
#  define D_KEY 100

#  define L_SHIFT_KEY 65505
# endif

// Full X11 event list; only KeyPress/Release, ButtonPress/Release,
// MotionNotify, Expose and DestroyNotify are actually delivered by mlx
// on both Linux and MacOS, the rest exist only via mlx_hook on Linux.
enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_ENTER = 7,
	ON_LEAVE = 8,
	ON_FOCUSIN = 9,
	ON_FOCUSOUT = 10,
	ON_KEYMAP = 11,
	ON_EXPOSE = 12,
	ON_GRAPHICSEXPOSE = 13,
	ON_NOEXPOSE = 14,
	ON_VISIBILITY = 15,
	ON_CREATE = 16,
	ON_DESTROY = 17,
	ON_UNMAP = 18,
	ON_MAP = 19,
	ON_MAPREQUEST = 20,
	ON_REPARENT = 21,
	ON_CONFIGURE = 22,
	ON_CONFIGUREREQUEST = 23,
	ON_GRAVITY = 24,
	ON_RESIZEREQUEST = 25,
	ON_CIRCULATE = 26,
	ON_CIRCULATEREQUEST = 27,
	ON_PROPERTY = 28,
	ON_SELECTIONCLEAR = 29,
	ON_SELECTIONREQUEST = 30,
	ON_SELECTIONNOTIFY = 31,
	ON_COLORMAP = 32,
	ON_CLIENTMESSAGE = 33,
	ON_MAPPING = 34,
	ON_GENERICEVENT = 35,
	ON_LASTEVENT = 36
};

// Event masks, to be passed as the mask argument to mlx_hook()
enum
{
	MASK_NONE = 0,
	MASK_KEYPRESS = (1 << 0),
	MASK_KEYRELEASE = (1 << 1),
	MASK_BUTTONPRESS = (1 << 2),
	MASK_BUTTONRELEASE = (1 << 3),
	MASK_ENTERWINDOW = (1 << 4),
	MASK_LEAVEWINDOW = (1 << 5),
	MASK_POINTERMOTION = (1 << 6),
	MASK_POINTERMOTIONHINT = (1 << 7),
	MASK_BUTTON1MOTION = (1 << 8),
	MASK_BUTTON2MOTION = (1 << 9),
	MASK_BUTTON3MOTION = (1 << 10),
	MASK_BUTTON4MOTION = (1 << 11),
	MASK_BUTTON5MOTION = (1 << 12),
	MASK_BUTTONMOTION = (1 << 13),
	MASK_KEYMAPSTATE = (1 << 14),
	MASK_EXPOSURE = (1 << 15),
	MASK_VISIBILITYCHANGE = (1 << 16),
	MASK_STRUCTURENOTIFY = (1 << 17),
	MASK_RESIZEREDIRECT = (1 << 18),
	MASK_SUBSTRUCTURENOTIFY = (1 << 19),
	MASK_SUBSTRUCTUREREDIRECT = (1 << 20),
	MASK_FOCUSCHANGE = (1 << 21),
	MASK_PROPERTYCHANGE = (1 << 22),
	MASK_COLORMAPCHANGE = (1 << 23),
	MASK_OWNERGRABBUTTON = (1 << 24)
};

typedef enum e_direction
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
}	t_direction;

void	move_player(t_direction d, double speed);
void	rotate_player(t_direction d, double speed);

int		close_window(void);
int		key_down_handler(int keycode);
int		key_up_handler(int keycode);
int		mouse_click_handler(int mousecode, int x, int y);
int		mouse_move_handler(int x, int y);
int		loop_hook(void);

#endif /* HANDLERS_H */
