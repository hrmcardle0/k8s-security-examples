#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before setuid, user ID: %d\n", getuid());
    
    // Attempt to set the user ID to 0 (root)
    if (setuid(0) == -1) {
        perror("setuid failed");
        return 1;
    }
    
    printf("After setuid, user ID: %d\n", getuid());
    return 0;
}
