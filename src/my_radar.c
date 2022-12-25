/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar.c
*/

#include "objects.h"
#include "my_radar.h"

sfRenderWindow *init(instance_t *instance)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfContextSettings settings = {0, 0, 8, 0, 0, 0, 0};
    sfRenderWindow *window = sfRenderWindow_createUnicode(mode,
        (sfUint32 *) L"J̷̩̦͗̄̀͢͠’҉̞̳̐̽̾͢͝ă̶͇̌̕͜į̵̝̖͛̎̒͞ "
                     "m̵̛̰͑͐̔͢ͅi҈̡͈҇́̿̽s̵̢͇̉͞ d̴̢͇̦̅͊̕e҈̨̤̤҇͊ş̵̣̘̀̕ "
                     "ç̴̮̬̤̃̚͠ą̴͖̱̮̅͞r̸̡̦̗̐͛̒͞a̴̡͕̟҇̈́̚c҉̧̣͔͕̂͡t"
                     "̶̢̝̱͈̾̈́̒͠è҉̧͓̗̣̄͌̀͞r҈̧̦͌̂͋͞e҉̡͖̟͌͑̚͞ś̴̨͕͡ "
                     "ș̶̢̯҇̈́p̵͕͉͙̃̑͌̕͜é̵̡̬̯͖̆̏͞c̷̡̛͉̎̚į̸̛̱͑̚a̶̧͙͙̩̋͛̕u"
                     "҈̨̜͙̌͝x̴̡̠͋̏͝ į̸͉̽̏̋͡c҈̫̥̏͂͜͞ͅī̸̢͖͙̍̕", sfClose,
                     &settings);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setPosition(window, (sfVector2i) {0, 0});
    return window;
}

void event_manager(sfRenderWindow *window)
{
    sfEvent event;
    while(sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

int create_backgound(instance_t *instance)
{
    instance->s_map = sfSprite_create();
    sfSprite_setTexture(instance->s_map,
        sfTexture_createFromImage(instance->i_map, NULL), sfFalse);
    return EPITECH_SUCCESS;
}

int my_radar(char *path)
{
    instance_t *instance = malloc(sizeof(instance_t));
    if (open_file(path, instance) == EPITECH_FAILLURE)
        return EPITECH_FAILLURE;
    create_planes(instance);
    create_backgound(instance);
    instance->window = init(instance);
    while (sfRenderWindow_isOpen(instance->window)) {
        event_manager(instance->window);
        update_planes(instance);
        sfRenderWindow_clear(instance->window, sfBlack);
        sfRenderWindow_drawSprite(instance->window, instance->s_map, NULL);
        display_planes(instance);
        sfRenderWindow_display(instance->window);
    }
    return 0;
}
