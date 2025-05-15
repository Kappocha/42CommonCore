#include "libft.h"

int main(void)
{
    ft_putnbr_fd(0, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(42, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-2147483648, 1); // INT_MIN
    write(1, "\n", 1);

    ft_putnbr_fd(2147483647, 1);  // INT_MAX
    write(1, "\n", 1);

    ft_putnbr_fd(-12345, 1);
    write(1, "\n", 1);

    return 0;
}
