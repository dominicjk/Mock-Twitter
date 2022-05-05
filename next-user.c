#include <stdio.h>
#include "next-user.h"


/* next user function goes to the next user indicating it has skipped it's turn
 * the profile data of the user is displayed on the standard output such as the name, follower and followees
 */
void nextuser(user* a) {

    printf("\n\nYou have chosen to go to the next user\n");

    //print user's profile
    printf("==================| PROFILE\n", a -> username);
    printf("User: %s | Followers: %d | Following: %d\n", a -> username, a -> num_followers, a -> num_following);
    printf("\n");

    //print the list of follower (unless user has no followers)
    if (a -> num_followers > 0) {
        printf("==================| FOLLOWERS\n");
        int lim = a -> num_followers;
        for (int i = 0; i < lim; i++) {
            printf("%s, ", &a->followers[i][USR_LENGHT]); //print user's followers
        }
        printf("\n");
    }

    //print the list of names the user is following (unless user is not following anyone)
    if (a -> num_following > 0) {
        printf("==================| FOLLOWING\n");
        int lim2 = a->num_following;
        for (int j = 0; j < lim2; j++) {
            printf("%s, ", &a->following[j][USR_LENGHT]);
        }
    }
    printf("\n\n");
}
