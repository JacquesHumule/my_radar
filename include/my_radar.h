/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar.h
*/

#ifndef EPITECH_FAILLURE
    #define EPITECH_FAILLURE 84
#endif

#ifndef EPITECH_SUCCESS
    #define EPITECH_SUCCESS 0
#endif

#ifndef MY_RADAR_
    #define MY_RADAR_
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
int swap_planes(instance_t *instance, size_t i);
int check_collision(instance_t *instance);
quadtree_t *create_tree(void);
int display_bb(quadtree_t *head, instance_t *instance);
int atc_create(instance_t *instance);
int atc_display(instance_t *instance);
bool planes_in_atc_area(plane_t *plane, instance_t *instance);
int create_bounding_box(quadtree_t *head);
void free_atc_array(atc_array_t *array);
void free_plane_array(plane_array_t *array);
void free_quadtree(quadtree_t *quadtree);

#endif //MY_RADAR_
