#ifndef ERRORS_H
# define ERRORS_H

/*
*****************************ERRORS TYPES************************************
*/

# define ERR "Error : "
# define ERR_NAME "File name is incorrect\n"
# define ERR_SCENE "Something is missing or too much in the description\n"
# define ERR_ARG "The number of arguments is incorrect\n"
# define ERR_OPEN "The file cannot be opened correctly\n"
# define ERR_RESO "The resolution is incorrect\n"
# define ERR_COLOR "The RGB values are incorrect\n"
# define ERR_PATH "The path is invalid\n"
# define ERR_MAP "A forbidden char has slipped into the map\n"
# define ERR_GNL "Scene file can't be read\n"
# define ERR_ELEM "Incorrect number or type of identifiers\n"
# define ERR_RGB "Incorrect RGB values\n"
# define ERR_CHAR " A forbidden char has slipped into the description\n"
# define ERR_PLAYER "There are too many or not enough players on the map\n"

# define ERR_NO_MAP "No map was found in the file\n"

/*
*****************************USAGES TYPES************************************
*/

# define X "/\n"
# define INT_X "Please enter an int\n"
# define USAGE "Usage : "
# define NAME_ARG "A correct file name must have a '.cub' extension\n"
# define FILE "The file could not be found\n"
# define SCENE "Please, enter a valid description of the scene\n"
# define NB_ARG "Please, enter 2 arguments\n"
# define COLOR "RGB values should be between 0 and 255\n"
# define PATH "The file must be an .xpm\n"
# define MAP "Please, enter a valid map\n"
# define ELEM "Please, enter 8 correct identifiers\n"
# define RESO "Enter a resolution greater than 0 and smaller than int max\n"
# define RGB "RGB values should be between 0 and 255\n"
# define CHAR "The elements of the description can only be separated by spaces\n"
# define PLAYER "Please, indicate only 1 player on the map\n"

#endif