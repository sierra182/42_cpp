NAME = myPhoneBook
CXX = c++

HDR_DIR = .
SRC_DIR = .

CFLAGS = $(HDRFLAGS)  -g -Wall -Wextra -Werror -std=c++98
LDFLAGS = 

HDRFLAGS = -I$(SRC_DIR)/Class
HDR = \
	$(HDR_DIR)/Account.hpp \

SRC = \
	$(SRC_DIR)/tests.cpp \

OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re intro l newline backline emoticon 

all: intro $(NAME) 

l: emoticon $(NAME) 

$(SRC_DIR)/%.o : $(SRC_DIR)/%.cpp $(HDR) $(X_HDR)
	@echo "\033[0;32m compiling $(NAME) object $<...\033[0m" 🚀
	@$(CXX) $(CFLAGS) $< -c -o $@

$(NAME) : $(OBJ) 
	@echo "\n\033[0;32m linking $(NAME) objects...\033[0m 🚀\n\n 💗 💎 💎 💗\n"
	@$(CXX) $(OBJ) $(LDFLAGS) -o $@

emoticon:
	@echo "\n 💗 😀 😃 😍\n"

newline: 
	@echo ""

backline: 
	@echo "\033[A\033[A"

intro:
	@echo -e "\033[?25l"
	clear
	@sleep 1
	@echo -n " Wake"
	@sleep .4
	@echo " up...\n"
	@sleep .1
	@echo -n " "
	@letters="The Makefile has you..."; \
	echo "\033[1;92m$$letters\033[0m" | awk '{split($$0, chars, ""); \
	for (i = 1; i <= length($$0); i++) \
	{printf "%s", chars[i]; system("sleep 0.2");}} \
	system("sleep 1");' 
	@words="\n\n\tFollow \n\t\tthe \t\b\b\033[0;96mColored! \
	\n\n\t\t\b\b\b\b\b\b\033[1;95mUnicorne!\033[0m...🦄\n\n"; \
	for j in $${words}; do \
		echo -n "$$j"; \
		sleep .4; \
	done
	@sleep .4
	@cat mfile_design
	@$(MAKE) -s emoticon
	@echo "\033[?25h"
	@$(MAKE) -s backline

clean:
	@echo "\n cleanning $(NAME) objects 🧻"
	@rm -f $(OBJ)
	@$(MAKE) -s newline	

fclean:
	@echo "\n cleanning $(NAME) objects 🧻"
	@rm -f $(OBJ)
	@echo " cleanning $(NAME) 🚽" 
	@rm -f $(NAME)	
	@$(MAKE) -s newline	

re: fclean backline l