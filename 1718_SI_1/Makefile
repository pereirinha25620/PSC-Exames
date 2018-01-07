##
# GCC Config
##
CC = gcc
CC_FLGS = -Wall -o

##
# Targets:
##
ALL = all
CHECK_FOR_ALT_BIT = check_for_alt_bit
STRING_TRIM = strtrim

$(ALL) : $(CHECK_FOR_ALT_BIT) $(STRING_TRIM)

$(CHECK_FOR_ALT_BIT) : $(CHECK_FOR_ALT_BIT).c
	$(CC) $(CC_FLGS) $(CHECK_FOR_ALT_BIT) $(CHECK_FOR_ALT_BIT).c

$(STRING_TRIM) : $(STRING_TRIM).c
	$(CC) $(CC_FLGS) $(STRING_TRIM) $(STRING_TRIM).c


clean : 
	rm $(CHECK_FOR_ALT_BIT)
	rm $(STRING_TRIM)
