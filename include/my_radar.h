/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar.h
*/

#ifndef MY_RADAR_
    #define MY_RADAR_
    #define EPITECH_FAILLURE 84
    #define EPITECH_SUCCESS 0
    #include "objects.h"
int open_file(char *path, instance_t *instance);
int my_radar(char *path);
int create_planes(instance_t *instance);
int display_planes(instance_t *instance);
int update_planes(instance_t *instance);
float long_parse(char const * str);
float lat_parse(char const * str);
atc_array_t *atc_array_create(linked_list_t *list_atc);
plane_array_t *plane_array_create(linked_list_t *list_plane);

#endif //MY_RADAR_
