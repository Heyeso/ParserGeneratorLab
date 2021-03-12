#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
        char name[64];
        int volume;
        char on_off[10];
} room_type;

room_type room_list[128];

int current_room_index = 0;

room_type find_room_data(char *roomname)
{
        room_type data;
        int found_it = 0;
        for (int i = 0; i < current_room_index; i++)
        {
                if (strcmp(room_list[i].name, roomname) == 0)
                {
                        data = room_list[i];
                        printf("\t  room:  %s\n", data.name);
                        printf("\tstatus:  %s\n", data.on_off);
                        printf("\tvolume:  %d\n", data.volume);
                        found_it = 1;
                }
        }
        if (found_it == 0)
        {
                printf("\t'did not find %s'\n", roomname);
        }
        return data;
}

int set_room_status(char *roomname, char *onoff)
{
        int result = 0;
        for (int i = 0; i < current_room_index; i++)
        {
                if (strcmp(room_list[i].name, roomname) == 0)
                {
                        strcpy(room_list[i].on_off, onoff);
                        result = 1;
                        printf("\t'%s' is '%s'\n", roomname, onoff);
                }
        }
        if (result == 0)
                printf("\t'did not find %s'\n", roomname);
        return result;
}

int set_room_volume(char *roomname, int volume)
{
        int result = 0;
        for (int i = 0; i < current_room_index; i++)
        {
                if (strcmp(room_list[i].name, roomname) == 0)
                {
                        room_list[i].volume = volume;
                        result = 1;
                }
        }
        return result;
}
// increase_volume will increase the volume of the room by 1 if the status for the room is on. If the room is off, it will print a message <room> is off
int increase_room_volume(char *roomname)
{
        int result = 0;
        for (int i = 0; i < current_room_index; i++)
        {
                if (strcmp(room_list[i].name, roomname) == 0)
                {
                        if (strcmp(room_list[i].on_off, "on") == 0)
                        {
                                room_list[i].volume++;
                                result = 1;
                        }
                }
        }
        return result;
}
// decrease_volume will decrease the volume of the room by 1 if the status for the room is on. If the room is off, it will print a message <room> is off
int decrease_room_volume(char *roomname)
{
        int result = 0;
        for (int i = 0; i < current_room_index; i++)
        {
                if (strcmp(room_list[i].name, roomname) == 0)
                {
                        if (strcmp(room_list[i].on_off, "on") == 0)
                        {
                                room_list[i].volume--;
                                result = 1;
                        }
                }
        }
        return result;
}
