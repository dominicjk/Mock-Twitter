#include <stdio.h>
#include "follow-user.h"

void follow(user* a, user* b) {
    int bool = 0; //declare bool value
    //search through the following list to see if user already follows user b
    for (int i = 0; i <= a->num_following; i++) {

        if (strcmp(a->following[i], b->username) == 0) {
            //if a match is found, change 'bool' to false
            bool = 1;
        }
    }

    //if a does not follow be already
    if (bool == 0) {
        strcpy(&a->following[a->num_following][USR_LENGHT], &b->username);
        strcpy(&b->followers[b->num_followers][USR_LENGHT], &a->username);
        a->num_following++;
        b->num_followers++;
    }
        //if a does follow b
    else {
        printf("%s already follows %s\n", a->username, b->username);
    }
}
