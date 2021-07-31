#include "cavans.h"

cavans *build_cavans(int newRowsize, int newColumnsize)
{
    cavans *init_cavans = (cavans *)malloc(sizeof(cavans));
    init_cavans->rowsize = newRowsize;
    init_cavans->columnsize = newColumnsize;
    init_cavans->pArray = (bool **)malloc(sizeof(bool *) * init_cavans->rowsize);
    for (size_t i = 0; i < init_cavans->rowsize; i++)
    {
        init_cavans->pArray[i] = (bool *)malloc(sizeof(bool) * init_cavans->columnsize);
    }
    init_cavans->is_printed_cavans = false;
    init_cavans->is_drawn_grid = false;
    init_cavans->is_drawn_square = false;
    return init_cavans;
}

void set_cavans(cavans *p_cavans, int row_num, int column_num, bool bool_value)
{
    if ((row_num < p_cavans->rowsize) && (column_num < p_cavans->columnsize))
    {
        p_cavans->pArray[row_num][column_num] = bool_value;
        return;
    }
    else
    {
        fprintf(stderr, "Value range overflow!\n");
        exit(1);
    }
}

void print_cavans(cavans *p_cavans)
{
    if (p_cavans->is_printed_cavans == false)
    {
        p_cavans->is_printed_cavans = true;
        p_cavans->is_drawn_grid = false;
        p_cavans->is_drawn_square = false;
    }

    for (int y = 0; y < p_cavans->rowsize; y++)
    {
#ifdef _KEEP_SPACE_
        for (size_t x = 0; x < p_cavans->columnsize - 1; x++)
        {
            if (p_cavans->pArray[y][x])
                printf("* ");
            else
                printf("  ");
        }
        if (p_cavans->pArray[y][p_cavans->columnsize - 1])
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
#else
        for (size_t x = 0; x < p_cavans->columnsize; x++)
        {
            if (p_cavans->pArray[y][x])
                printf("*");
            else
                printf(" ");
        }
#endif
        printf("\n");
    }
    return;
}

void draw_grid(cavans *p_cavans)
{
    if (p_cavans->is_drawn_grid == false)
    {
        p_cavans->is_drawn_grid = true;
        p_cavans->is_drawn_square = false;
        p_cavans->is_printed_cavans = false;
    }

    for (int y = 0; y < p_cavans->rowsize * 2 + 1; y++)
    {
        for (int x = 0; x < p_cavans->columnsize * 4 + 1; x++)
        {
            if (y % 2 == 1)
            {
                if (x % 4 == 2)
                {
                    if (p_cavans->pArray[(y - 1) / 2][(x - 2) / 4])
                        printf("1");
                    else
                        printf("0");
                }
                else if (x % 4 == 0)
                {
                    printf("│");
                }
                else if (x % 2 == 1)
                {
                    printf(" ");
                }
            }
            else
            {
                if (y == 0)
                {
                    if (x == 0)
                    {
                        printf("┌");
                    }
                    else if (x == p_cavans->columnsize * 4)
                    {
                        printf("┐");
                    }
                    else if (x % 4 == 0)
                    {
                        printf("┬");
                    }
                    else
                    {
                        printf("─");
                    }
                }
                else if (y == p_cavans->rowsize * 2)
                {
                    if (x == 0)
                    {
                        printf("└");
                    }
                    else if (x == p_cavans->columnsize * 4)
                    {
                        printf("┘");
                    }
                    else if (x % 4 == 0)
                    {
                        printf("┴");
                    }
                    else
                    {
                        printf("─");
                    }
                }
                else
                {
                    if (x == 0)
                    {
                        printf("├");
                    }
                    else if (x == p_cavans->columnsize * 4)
                    {
                        printf("┤");
                    }
                    else if (x % 4 == 0)
                    {
                        printf("┼");
                    }
                    else
                    {
                        printf("─");
                    }
                }
            }
        }
        printf("\n");
    }
    return;
}

void draw_square(cavans *p_cavans)
{
    if (p_cavans->is_drawn_square == false)
    {
        p_cavans->is_drawn_square = true;
        p_cavans->is_drawn_grid = false;
        p_cavans->is_printed_cavans = false;
    }

    for (int y = 0; y < p_cavans->rowsize * 2 + 1; y++)
    {
        for (int x = 0; x < p_cavans->columnsize * 4 + 1; x++)
        {
            static bool y_top, y_bottom, x_left, x_right;

            y_top = (y / 2 == 0) ? true : false;
            y_bottom = (y / 2 == (p_cavans->rowsize)) ? true : false;
            x_left = (x / 4 == 0) ? true : false;
            x_right = (x / 4 == (p_cavans->columnsize)) ? true : false;

            if (y % 2 == 1) //中心行
            {
                if (x % 4 == 0)
                {
                    if (x_right)
                    {
                        if (p_cavans->pArray[(y - 1) / 2][x / 4 - 1])
                        {
                            printf("│");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    else if (x_left)
                    {
                        if (p_cavans->pArray[(y - 1) / 2][x / 4])
                        {
                            printf("│");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    else
                    {
                        if (p_cavans->pArray[(y - 1) / 2][x / 4] || p_cavans->pArray[(y - 1) / 2][x / 4 - 1])
                        {
                            printf("│");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                }
                else if (x % 4 == 1)
                {
                    printf(" ");
                }
                else if (x % 4 == 2)
                {
                    if (p_cavans->pArray[(y - 1) / 2][(x - 2) / 4])
                    {
                        printf("1");
                        //printf(" ");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                else if (x % 4 == 3)
                {
                    printf(" ");
                }
            }
            else //边框行
            {
                if (x % 4 == 0) //左上角
                {
                    if (y_bottom)
                    {
                        if (x_right)
                        {
                            if (p_cavans->pArray[y / 2 - 1][x / 4 - 1])
                            {
                                printf("┘");
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                        else if (x_left)
                        {
                            if (p_cavans->pArray[y / 2 - 1][x / 4])
                            {
                                printf("└");
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                        else
                        {
                            if (p_cavans->pArray[y / 2 - 1][x / 4])
                            {
                                if (p_cavans->pArray[y / 2 - 1][x / 4 - 1])
                                {
                                    printf("┴");
                                }
                                else
                                {
                                    printf("└");
                                }
                            }
                            else if (p_cavans->pArray[y / 2 - 1][x / 4 - 1])
                            {
                                printf("┘");
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                    }
                    else if (y_top)
                    {
                        if (x_right)
                        {
                            if (p_cavans->pArray[y / 2][x / 4 - 1])
                            {
                                printf("┐");
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                        else if (x_left)
                        {
                            if (p_cavans->pArray[y / 2][x / 4])
                            {
                                printf("┌");
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                        else
                        {
                            if (p_cavans->pArray[y / 2][x / 4])
                            {
                                if (p_cavans->pArray[y / 2][x / 4 - 1])
                                {
                                    printf("┬");
                                }
                                else
                                {
                                    printf("┌");
                                }
                            }
                            else if (p_cavans->pArray[y / 2][x / 4 - 1])
                            {
                                printf("┐");
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                    }
                    else
                    {
                        if (x_right)
                        {
                            if (p_cavans->pArray[y / 2 - 1][x / 4 - 1])
                            {
                                if (p_cavans->pArray[y / 2][x / 4 - 1])
                                {
                                    printf("┤");
                                }
                                else
                                {
                                    printf("┘");
                                }
                            }
                            else if (p_cavans->pArray[y / 2][x / 4 - 1])
                            {
                                printf("┐");
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                        else if (x_left)
                        {
                            if (p_cavans->pArray[y / 2 - 1][x / 4])
                            {
                                if (p_cavans->pArray[y / 2][x / 4])
                                {
                                    printf("├");
                                }
                                else
                                {
                                    printf("└");
                                }
                            }
                            else if (p_cavans->pArray[y / 2][x / 4])
                            {
                                printf("┌");
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                        else
                        {
                            if (p_cavans->pArray[y / 2 - 1][x / 4 - 1])
                            {
                                if (p_cavans->pArray[y / 2 - 1][x / 4])
                                {
                                    if (p_cavans->pArray[y / 2][x / 4 - 1])
                                    {
                                        if (p_cavans->pArray[y / 2][x / 4])
                                        {
                                            printf("┼");
                                        }
                                        else
                                        {
                                            printf("┼");
                                        }
                                    }
                                    else
                                    {
                                        if (p_cavans->pArray[y / 2][x / 4])
                                        {
                                            printf("┼");
                                        }
                                        else
                                        {
                                            printf("┴");
                                        }
                                    }
                                }
                                else
                                {
                                    if (p_cavans->pArray[y / 2][x / 4 - 1])
                                    {
                                        if (p_cavans->pArray[y / 2][x / 4])
                                        {
                                            printf("┼");
                                        }
                                        else
                                        {
                                            printf("┤");
                                        }
                                    }
                                    else
                                    {
                                        if (p_cavans->pArray[y / 2][x / 4])
                                        {
                                            printf("┼");
                                        }
                                        else
                                        {
                                            printf("┘");
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (p_cavans->pArray[y / 2 - 1][x / 4])
                                {
                                    if (p_cavans->pArray[y / 2][x / 4 - 1])
                                    {
                                        if (p_cavans->pArray[y / 2][x / 4])
                                        {
                                            printf("┼");
                                        }
                                        else
                                        {
                                            printf("┼");
                                        }
                                    }
                                    else
                                    {
                                        if (p_cavans->pArray[y / 2][x / 4])
                                        {
                                            printf("├");
                                        }
                                        else
                                        {
                                            printf("└");
                                        }
                                    }
                                }
                                else
                                {
                                    if (p_cavans->pArray[y / 2][x / 4 - 1])
                                    {
                                        if (p_cavans->pArray[y / 2][x / 4])
                                        {
                                            printf("┬");
                                        }
                                        else
                                        {
                                            printf("┐");
                                        }
                                    }
                                    else
                                    {
                                        if (p_cavans->pArray[y / 2][x / 4])
                                        {
                                            printf("┌");
                                        }
                                        else
                                        {
                                            printf(" ");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if (x % 4 == 1)
                {
                    if (y_bottom)
                    {
                        if (p_cavans->pArray[y / 2 - 1][(x - 1) / 4])
                        {
                            printf("─");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    else if (y_top)
                    {
                        if (p_cavans->pArray[y / 2][(x - 1) / 4])
                        {
                            printf("─");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    else
                    {
                        if (p_cavans->pArray[y / 2][(x - 1) / 4] || p_cavans->pArray[y / 2 - 1][(x - 1) / 4])
                        {
                            printf("─");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                }
                else if (x % 4 == 2)
                {
                    if (y_bottom)
                    {
                        if (p_cavans->pArray[y / 2 - 1][(x - 2) / 4])
                        {
                            printf("─");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    else if (y_top)
                    {
                        if (p_cavans->pArray[y / 2][(x - 2) / 4])
                        {
                            printf("─");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    else
                    {
                        if (p_cavans->pArray[y / 2][(x - 2) / 4] || p_cavans->pArray[y / 2 - 1][(x - 2) / 4])
                        {
                            printf("─");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                }
                else if (x % 4 == 3)
                {
                    if (y_bottom)
                    {
                        if (p_cavans->pArray[y / 2 - 1][(x - 3) / 4])
                        {
                            printf("─");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    else if (y_top)
                    {
                        if (p_cavans->pArray[y / 2][(x - 2) / 4])
                        {
                            printf("─");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    else
                    {
                        if (p_cavans->pArray[y / 2][(x - 2) / 4] || p_cavans->pArray[y / 2 - 1][(x - 3) / 4])
                        {
                            printf("─");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    return;
}

void free_cavans(cavans *p_cavans)
{
    for (size_t i = 0; i < p_cavans->rowsize; i++)
    {
        free(p_cavans->pArray[i]);
    }
    free(p_cavans->pArray);
    free(p_cavans);
    return;
}

void rewind_cavans(cavans *p_cavans)
{
    if (p_cavans->is_printed_cavans == true)
    {
        char *column_blank = (char *)malloc(sizeof(char) * (p_cavans->columnsize + 1));

        for (size_t i = 0; i < p_cavans->columnsize; i++)
        {
            column_blank[i] = ' ';
        }

        column_blank[p_cavans->columnsize] = '\0';
        printf("\033[%dA\r", p_cavans->rowsize);
        fflush(stdout);
        return;
    }
    else if (p_cavans->is_drawn_grid == true)
    {
        return;
    }
    else if (p_cavans->is_drawn_square == true)
    {
        return;
    }
}

void print_logo()
{
    printf("\n┌───┐\n│# #│\n└─^─┘\n /│\\\n  │\n / \\\n");
    return;
}
