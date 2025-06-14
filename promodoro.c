#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Clear terminal screen
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Tomato / Work graphic
void print_tomato() {
    printf("\n");
    printf("           POMODORO TIMER\n");
    printf("    +==================================+\n");
    printf("    |        .-\"\"\"\"--.                 |\n");
    printf("    |       /          \\               |\n");
    printf("    |      |    .---.   |              |\n");
    printf("    |      |   /     \\  |              |\n");
    printf("    |      |  | () () | |              |\n");
    printf("    |       \\  \\  ^  /  /              |\n");
    printf("    |        '--.___.--'               |\n");
    printf("    |         FOCUS TIME!              |\n");
    printf("    +==================================+\n");
    printf("\n");
}

// Break graphic
void print_break_graphic() {
    printf("\n");
    printf("           BREAK TIME\n");
    printf("    +==================================+\n");
    printf("    |           _  _                   |\n");
    printf("    |          ( `   )_                |\n");
    printf("    |         (    )    `)             |\n");
    printf("    |       (_   (_ .  _) _)           |\n");
    printf("    |                                  |\n");
    printf("    |        +============+            |\n");
    printf("    |        |    RELAX   |            |\n");
    printf("    |        |  & RECHARGE |           |\n");
    printf("    |        +============+            |\n");
    printf("    +==================================+\n");
    printf("\n");
}

// Progress bar printer
void print_progress_bar(int current, int total) {
    int bar_width = 30;
    int progress = (current * bar_width) / total;

    printf("    Progress: [");
    for (int i = 0; i < bar_width; i++) {
        if (i < progress) printf("#");
        else printf("-");
    }
    printf("] %d%%\n", (current * 100) / total);
}

// Countdown timer
void countdown(int seconds) {
    int total_seconds = seconds;
    while (seconds > 0) {
        clear_screen();
        int min = seconds / 60;
        int sec = seconds % 60;

        printf("\n");
        printf("    +==================================+\n");
        printf("    |                                  |\n");
        printf("    |         TIME LEFT                |\n");
        printf("    |                                  |\n");
        printf("    |           %02d:%02d              |\n", min, sec);
        printf("    |                                  |\n");
        printf("    +==================================+\n");
        printf("\n");

        print_progress_bar(total_seconds - seconds, total_seconds);

        fflush(stdout);
        sleep(1);
        seconds--;
    }
    printf("\n    +===== TIMES UP! =====+\n\n");
}

// Main program
int main() {
    int work_duration = 25 * 60;  // 25 minutes
    int break_duration = 5 * 60;  // 5 minutes
    int cycles = 4;               // Number of Pomodoro cycles

    clear_screen();
    printf("\n");
    printf("    +==============================================+\n");
    printf("    |      WELCOME TO POMODORO PRODUCTIVITY TIMER  |\n");
    printf("    +==============================================+\n");
    printf("    |  %d cycles x 25min work + 5min break          |\n", cycles);
    printf("    |  Stay focused and productive!                |\n");
    printf("    +==============================================+\n");
    printf("\n    Press ENTER to start...");
    getchar();

    for (int i = 1; i <= cycles; i++) {
        clear_screen();
        print_tomato();
        printf("    CYCLE %d OF %d\n", i, cycles);
        printf("    WORK SESSION: 25 MINUTES\n\n");
        printf("    Press ENTER to begin work session...");
        getchar();

        countdown(work_duration);

        if (i < cycles) {
            clear_screen();
            print_break_graphic();
            printf("    CYCLE %d COMPLETE!\n", i);
            printf("    BREAK TIME: 5 MINUTES\n\n");
            printf("    Press ENTER to start break...");
            getchar();
            countdown(break_duration);
        }
    }

    clear_screen();
    printf("\n");
    printf("    +==============================================+\n");
    printf("    |                                              |\n");
    printf("    |        CONGRATULATIONS!                     |\n");
    printf("    |                                              |\n");
    printf("    |     ALL %d POMODORO CYCLES COMPLETED!        |\n", cycles);
    printf("    |                                              |\n");
    printf("    |        PRODUCTIVITY MASTER!                 |\n");
    printf("    |                                              |\n");
    printf("    |           You did an amazing job!            |\n");
    printf("    |                                              |\n");
    printf("    +==============================================+\n");
    printf("\n");

    return 0;
}
