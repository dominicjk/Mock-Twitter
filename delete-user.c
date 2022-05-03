#include "delete-user.h"

//DELETE ACCOUNT FUNCTION
/*an outer loop will iterate over all the users in the system. When the user intended for deletion is
  matched, then each subsequent user is shifted one place to the left of the user array, which overwrites
  the deleted user.
  The special case is when the user for deletion is the last user in the array. In that case, we don't shift
  any subsequent users (because there are none). Instead we only decrement the total user count, so when we
  iterate over each user in the main function, the last user will be skipped.
*/
void deleteuser(user* a, twitter *system) {
    for (int i = 0; i < system -> num_users; i++) {
        if (strcmp(a ->username, system -> users[i].username) == 0) {

            //inner loop will shift each subsequent user to the left.
            for(int j = i; j < system -> num_users; j++){

                //if deleted user is not last (if it is last just decrement the number of users)
                if (i < system -> num_users - 1) {
                    struct user *a = &system->users[j];
                    struct user *b = &system->users[j + 1];

                    *a = *b; //overwrite deleted user
                }
            }
        }
    }

    system -> num_users--; //decrement total user count
}
