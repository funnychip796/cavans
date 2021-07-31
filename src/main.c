//edited by zlf, 2021
#include "cavans.h"
#include <unistd.h>

int main()
{
        //printf("\033[?25l");
        printf("\033[?25l\e[?1049h");
        size_t count = 29;
        cavans *p_inst = build_cavans(count, count);

        // for (size_t i = 0; i < count; i++)
        // {
        //         set_cavans(p_inst, i, i, true);
        //         set_cavans(p_inst, (count - 1) - i, i, true);
        //         // set_cavans(p_inst, 0, i, true);
        //         // set_cavans(p_inst, i, 0, true);
        //         // set_cavans(p_inst, i, count - 1, true);
        //         // set_cavans(p_inst, count - 1, i, true);
        // }

        // for (size_t i = 0; i < count; i++)
        // {
        //         for (size_t j = 0; j < count; j++)
        //         {
        //                 set_cavans(p_inst, i, j, true);
        //         }
        // }

        //print_cavans(p_inst);
        //draw_grid(p_inst);
        int t_delay = 10000;
        usleep(t_delay);

        // for (size_t i = 0; i < count; i++)
        // {
        //         for (size_t j = 0; j < count; j++)
        //         {
        //                 set_cavans(p_inst, i, j, (i + j) % 2 == 1);
        //                 draw_square(p_inst);
        //                 usleep(t_delay);
        //                 system("clear");
        //         }
        // }

        /*

        for (size_t cnt = 0; cnt < 2; cnt++)
        {
                bool var_flag;
                if (cnt == 0)
                {
                        var_flag = true;
                }
                else
                {
                        var_flag = false;
                }

                for (size_t i = 0; i < count; i++)
                {
                        set_cavans(p_inst, i, i, var_flag);
                        draw_square(p_inst);
                        usleep(t_delay);
                        clear_screen();
                }
                for (size_t i = 0; i < count; i++)
                {
                        set_cavans(p_inst, (count - 1) - i, i, var_flag);
                        draw_square(p_inst);
                        usleep(t_delay);
                        clear_screen();
                }
                for (size_t i = 0; i < count; i++)
                {
                        set_cavans(p_inst, 0, i, var_flag);
                        draw_square(p_inst);
                        usleep(t_delay);
                        clear_screen();
                }
                for (size_t i = 0; i < count; i++)
                {
                        set_cavans(p_inst, i, 0, var_flag);
                        draw_square(p_inst);
                        usleep(t_delay);
                        clear_screen();
                }
                for (size_t i = 0; i < count; i++)
                {
                        set_cavans(p_inst, i, count - 1, var_flag);
                        draw_square(p_inst);
                        usleep(t_delay);
                        clear_screen();
                }
                for (size_t i = 0; i < count; i++)
                {
                        set_cavans(p_inst, count - 1, i, var_flag);
                        draw_square(p_inst);
                        usleep(t_delay);
                        clear_screen();
                }
        }

        draw_square(p_inst);
        free_cavans(p_inst);
        clear_screen();

        */
        fflush(stdout);
        for (size_t i = 0; i < count; i++)
        {
                for (size_t j = 0; j < count; j++)
                {
                        rewind_cavans(p_inst);
                        set_cavans(p_inst, i, j, true);
                        print_cavans(p_inst);
                        usleep(t_delay);
                }
        }

        print_logo();
        //printf("\033[?25h");
        printf("\033[?25h\e[?1049l");

        return 0;
}
