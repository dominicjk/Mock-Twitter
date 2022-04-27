#ifndef COMP10050-PROJECT_TWITTER_CREATE_H
#define COMP10050-PROJECT_TWITTER_CREATE_H
#endif //TWITTER_PROJECT_TWITTER_CREATE_H
#define TWEET_LENGTH 270
#define USR_LENGHT 100
#define MAX_FOLLOWERS 30
#define MAX_FOLLOWING 30
#define MAX_TWEETS 100
#define MAX_USERS 100

typedef struct tweet{
    int id;
    char msg[TWEET_LENGTH];
    char author[USR_LENGHT];
}tweet;

typedef struct user {
    char username[USR_LENGHT];
    char followers[MAX_FOLLOWERS][USR_LENGHT];
    int num_followers;
    char following[MAX_FOLLOWING][USR_LENGHT];
    int num_following;
}user;

typedef struct twitter{
    tweet news_feed[MAX_TWEETS]; //define array tweets of type tweet
    user users[MAX_USERS];   //define array of users of type user
    int num_tweets; //define the number of tweets
    int num_users;  //define the number of users
} twitter;

void create_twitter_system(twitter * twitter_system);

