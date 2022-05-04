#include <stdio.h>
#include <stdlib.h>
#include "create_twitter.c"
#include "delete-user.c"
#include "follow-user.c"
#include "post-tweet.c"
#include "unfollow-user.c"
#include "next-user.c"


void CloseTwitter(void);

int main() {//start of main
    int key = 0;
    twitter twitter_system;  //define the twitter_system

    create_twitter_system(&twitter_system); //create users

    int num = twitter_system.num_tweets = 0;

    //print all users
    for (int i =0; i < twitter_system.num_users - 1; i++) {
        user usr = twitter_system.users[i];
        //print initial profile of each user
        printf("User %i: %s; Followers: %d; Following: %d\n",i + 1, usr.username, usr.num_followers, usr.num_followers );
    }
    //display function keys to the users
    printf("FUNCTION KEYS\n"
           "0 = Move To Next User\n"
           "1 = Follow\n"
           "2 = Post Tweet\n"
           "3 = Get News Feed\n"
           "4 = Unfollow\n"
           "5 = Delete Account\n"
           "6 = Close Twitter\n");

    //iterate over each user and ask user to prompt a function
    for (int i =0; i < twitter_system.num_users - 1; i++) {
        user * usr = &twitter_system.users[i]; //user in current iteration

        printf("input a function key for <%s>", &usr -> username);
        scanf("%d", &key);

        //while the user is still in turn (0 = go to next user)
        while (key != 0) {
            if (key == 1) {
                int index;
                user *a = &twitter_system.users[i];
                printf("Enter index of user that %s will follow: ", a->username);
                scanf("%d", &index);
                user *b = &twitter_system.users[index];
                follow(a, b);
            }
            else if (key == 2) {
                user *a = &twitter_system.users[i];
                tweet *c = &twitter_system.news_feed[twitter_system.num_tweets];
                post_tweet(a, c, &twitter_system);
            }
            else if (key == 3) {
             //News Feed
            }
            else if (key == 4) {
                user *a = &twitter_system.users[i];
                printf("Enter index of user that %s will unfollow ", a->username);
                int index;
                scanf("%d", &index);
                user *b = &twitter_system.users[index];
                unfollow(a, b);
            }
            else if (key == 5) {
            //Delete account
                user *a = &twitter_system.users[i];
                deleteuser(a, &twitter_system);
                //increment i since each user is shifted one place to the left after a user is deleted
                i = i - 1;
            }
            else if (key == 6) {
                CloseTwitter();
            }
            else {
                printf("function out of range\n");
            }

            //when function executes ask user to input a new function
            printf("enter new key");
            scanf("%d", &key);

        }
        if (key == 0) {
            nextuser(usr);
        }

        //reverse the counter if the loop is nearing it's end. this creates an infinite loop unless the CloseTwitter() function is called)
        if (i  == twitter_system.num_users - 2) {
            i = - 1;
        }
    }
}

//close twitter function
void CloseTwitter(void) {
    printf("You have chosen to close Twitter");
    exit(0);
}
