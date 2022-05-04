#include <stdio.h>
#include "unfollow-user.h"

void unfollow(user* a, user* b) {
    //for loop to find b's username in a's following array
    for (int i = 0; i < a->num_following; i++){

        //if b's username is found, execute the shifting
        if(strcmp(a ->following[i], b) == 0) {
            //for loop for shifting each username one place to the left of the array
            for(int j = i; j < a-> num_following; j++){
                strcpy(a->following[j], a->following[j+1]);
            }
        }
    }
    a -> num_following--;  //decrement number of users a is following by 1 (since b is unfollowed)
    b -> num_followers--;  //decrement number of followers b has (since a unfollowed b)
}