NAME = philo

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[0;33m
RESET = \033[0m

FLAGS = -Wall -Wextra -Werror -g

SOURCES = \
        philo.c \
		utils.c

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@cc $(FLAGS) $(OBJS) -o $(NAME) $(INC) $(LIB)
	@echo "$(GREEN)Compilation finished successfully!$(RESET)"

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: srcs/%.c | $(OBJDIR)
	@cc $(FLAGS) $(INC) -c $< -o $@

norm:
	@echo "Lancement de la norminette..."
	@norminette | grep -i "error" > norm_errors.log || true
	@if [ -s norm_errors.log ]; then \
		err_count=$$(wc -l < norm_errors.log); \
		echo "$(RED)$$err_count erreur(s) détectée(s) :$(RESET)"; \
		cat norm_errors.log; \
	else \
		echo "$(GREEN)OK - Aucun problème détecté par la norminette.$(RESET)"; \
	fi
	@rm norm_errors.log

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Cleaning all...$(RESET)"
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
