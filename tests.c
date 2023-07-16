#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     f_isdigit(char c) {
    int is_num;
    
    is_num = (c >= 48 && c <= 57);
    return (is_num);
}

int     f_isalpha(char c) {
    int is_lower;
    int is_upper;

    is_lower = (c >= 97 && c <= 122);
    is_upper = (c >= 65 && c <= 90);
    return ((is_lower || is_upper) ? 1 : 0);
}

int     f_isalnum(char c) {
    int    is_num;
    int    is_alpha;

    is_num = f_isdigit(c);
    is_alpha = f_isalpha(c);
    return ((is_num || is_alpha) ? 1 : 0);
}

int     f_isascii(int c) {
    int is_ascii = (c >= 0 && c <= 127);
    return (is_ascii ? 1 : 0);
}

int     f_isprint(int c) {
    int isprintable = (c >= 41);
    return (isprintable ? 1 : 0);
}

int     f_strlen(char *str){
    int i;
    i = 0; 
    while (*(str + i)) i++;
    return (i);
}

void    f_putchar_fd(char c, int f) {
    write(f, &c, 1);
}

void    f_putchar(char c) {
    f_putchar_fd(c, 1);
}

/*
**    To extract the last digit from n, we can mod by 10
**    To modify n such that the last digit is removed, we can divide by 10
*/

char    f_dtoc(int n) {
    if (n > 9 || n < 0) {
        return (0);
    }
    return ((n + 48));
}

int     f_strcmp(const char *s1, const char *s2) {
    int     i;
    int     n;
    int     m;

    n = f_strlen((char *)s1);
    m = f_strlen((char *)s2);
    i = 0;
    while (i < n && i < m) {
        if (!(s1[i] == s2[i])) return (-1);
        i++;
    }
    return (0);
}

int     f_strncmp(const char *s1, const char *s2, size_t l) {
    int     i;
    int     n;
    int     m;

    n = f_strlen((char *)s1);
    m = f_strlen((char *)s2);
    i = 0;
    while (i < n && i < m && i < (int)l) {
        if (!(s1[i] == s2[i])) return (-1);
        i++;
    }
    return (0);
}

char    *f_strcpy(char *dst, const char *src) {
    int     i;

    //n = f_strlen((char *)src);
    i = 0;
    while (dst[i]) {
        dst[i] = src[i];
        i++;
    }
    return (dst);
}

char    *f_strcat(char* s1, const char* s2 ) {
    int     n;
    int     m;
    int     i;

    n = f_strlen(s1);
    m = f_strlen((char *)s2);
    i = n;
    while (i < n + m) {
        s1[i] = s2[i - n];
        i++;
    }
    return (s1);
}

char    *f_strncat(char *s1, const char *s2, size_t n) {
    int i;
    int l;
    int m;

    l = f_strlen((char *)s1);
    m = f_strlen((char *)s2);
    i = 0;
    while (i + l < (int)n && i + l < m) {
        s1[i + l] = s2[i];
        i ++;
    }
    return (s1);
}

void    f_putnbr_fd(long long n, int fd) {
	long long tmp;

	tmp = n;
	if (tmp < 0) {
		tmp = -tmp;
		f_putchar_fd('-', fd);
	}
	if (tmp >= 10) {
		f_putnbr_fd(tmp / 10, fd);
		f_putnbr_fd(tmp % 10, fd);
	}
	else {
		f_putchar_fd(tmp + '0', fd);
	}
}

void    f_putnbr(long long n) {
    f_putnbr_fd(n , 1);
}

int     f_putstr(char *s) {
    int i;
    i = 0;
    while (*(s + i))
        f_putchar(*(s + i++));
    return (i);
}

int     f_putendl(char *s) {
    int bytes_written = 0;
    bytes_written = f_putstr(s);
    f_putchar('\n');
    return (bytes_written + 1);
}

int     f_iswhitespace(char c) {
    char*   whitespace_chars;
    int     i;

    whitespace_chars = " \t\r\n\f";
    i = 0;
    while (whitespace_chars[i]) {
        if (c == whitespace_chars[i++]) {
            return (1);
        }
    }
    
    return (0);
}

int     f_absval(int n) {
    return (n < 0 ? n * -1 : n);
}


char    *f_strncpy(char *dst, const char *src, size_t len) {
    int  n;
    int  i;

    n = f_strlen((char *)src);
    i = 0;
    while (i < (int)len && i < n) {
        dst[i] = src[i];
        i++;
    }
    return (dst);
}

/*
** test suites
*/

char    *f_strstr(const char *big, const char *little) {
    int n;
    int m;
    int i;
    int j;

    n = f_strlen((char *)big);
    m = f_strlen((char *)little);
    i = 0;
    while (*(big + i)) {
        j = 0;
        while (big[i] == little[j]) {
            j++;
        }
        if (j == m) {
            return ((char *)(big + i));
        }
    }
    return ((char *)(big + (i - m)));
}

char    *f_strnstr(const char *big, const char *sm, size_t len) {
    int     i;
    int     j;
    int     n;
    int     m;

    n = f_strlen((char *)big);
    m = f_strlen((char *)sm);
    i = 0;
    while (i < (int)len && i < n) {
        j = 0;
        while (big[i + j] == sm[j]) {
            j++;
        }
        if (j == m) {
            return ((char *)(big + i));
        }
        i++;
    }
    return (NULL);
}

char    f_array_len(char **arr){
    int i;

    i = 0; 
    while (arr[i] != NULL) {
        i++;
    }    
    return (i);
}

size_t  f_arr_len(char **arr) {
    int i;

    i = 0;
    while (arr[i] != NULL) {
        i++;
    }
    return (i);
}

/*
** cmp() return 0 if the inputs match and 1 if they don't match
*/

char    f_array_cmp(char **a1, char **a2, int (*cmp) (char*, char*)) {
    int i;
    int n;
    int m; 

    n = f_arr_len(a1);
    m = f_arr_len(a2);

    if (n != m) return 0;

    i = 0;
    while (i < n) {
        if (cmp(a1[i], a2[i])){
            return (1);    
        }
        i++;
    }
    return (0);
}

void    *f_memset(void *s, int c, size_t n) {
    char *ss;

    ss = (char *)s;
    while (n--){
        ss[n] = (char)c;
    }
    return ss;
}

char    *f_bzero(void *s, size_t n) {
    return (f_memset(s, 0, n));
}

void    *f_memalloc(size_t size) {
    void    *memory;
    memory = (void*)malloc(size);
    f_memset(memory, 0, size);
    return (memory);
}

char    **f_free_array(char** arr) {
    int i;
    int j;

    i = 0;
    while (arr[i] != NULL) {
        j = f_strlen(*arr);
        f_bzero(arr[i], f_strlen(*(arr + i)));
        free(arr[i]);
        i++;
    }
    return arr;
}

char    **f_array_resize(char ***array, size_t incr) {
    int     n;
    int     m;
    int     i;
    char    **new;

    n = f_array_len(*array);
    new = (char**)f_memalloc((n + incr) * sizeof(char *));
    i = 0;
    while (i < n) {
        m = f_strlen(*array[i]);
        f_strncpy(new[i], *array[i], m);
        i++;
    }
    free(*array);
    array = &new;
    return (*array);
}

char    *f_memcpy(char *dst, const char *src, size_t n) {
    size_t  i;
    i = 0;

    while (dst[i] && src[i] && i < n) {
        dst[i] = src[i];
    }
    return (dst);
}

char    *f_strnew(int l) {
    char *s;

    s = (char*)f_memalloc(l + 1);
    f_bzero(s, l);
    return(s);
}

char    *f_stralloc(char *src) {
    char    *new;
    int     n;

    n = f_strlen(src);
    new = (char*)f_memalloc(sizeof(char) * n);
    f_strncpy(new , src, n);
    return (new);
}

int     f_strcount(char *s, char c) {
    int     i;
    int     count;
    
    count = 0;
    i = 0;
    while (s[i]) {
        if (s[i] == c) {
            count++;
        }
        i++;
    }
    return (count);
}

char    *f_strchr(const char *s, int c) {
    int     i;

    i = 0;
    while (s[i]){
        if (s[i] == c) {
            return ((char*)(s + i));
        }
        i++;
    }
    return (NULL);
}

char    **f_array_append(char **array, char *item) {
    int n;

    n = f_array_len(array);
    f_array_resize(&array, 1);
    array[n] = f_stralloc(item);
    return (array);
}

char    **g(const char *str, char delim, char *cur, char **res, int len) {
    int     bytes;
    char    *next_delim;

    if (!str) {
        return (res);
    } else if (*str != delim) {
        next_delim = f_strchr(str, delim);
        bytes = next_delim != NULL ? next_delim - str : len - (int)str;
        return g(str + bytes, delim, f_strncat(cur, str, bytes), res, len);
    }
    f_array_append(res, cur);
    return g(str + 1, delim, f_bzero(cur, f_strlen(cur)), res, len);
}

char    **f_strsplit(char const *s, char c) {
    int     SIZE = 20;  
    char    *tmp;
    int     len;
    char    **res;

    len = f_strcount((char*)s, c);
    //add extra pointer since there will be one more word than there are delimiters
    //add extra pointer for terminator
    res = (char **)f_memalloc(sizeof(char *) * len + 1 + 1);
    tmp = f_strnew(SIZE);

    return (g(s, c, tmp, res, f_strlen((char*)s)));
}

void    test_strsplit( ) {
    char    *input = "This is a string";
    char    **res;
    int     i;
    char    *test[] = {
        "This", 
        "is", 
        "a", 
        "string",
        NULL
    };

    res = f_strsplit(input, ' ');
    i = 0; 
    while (test[i] != NULL) {
        assert(f_strcmp(res[i], test[i]) == 0);
        i++;
    }
    f_putstr("f_strsplit test successful");
}

void    test_strnstr() {
    char    *s1 = "thebiggestlittlestring";
    char    *s2 = "little";
    int     res;

    res = f_strcmp(f_strnstr(s1, s2, 23), "littlestring"); 
    if (!(res == 0 )) {
        f_putstr("strnstr fails");
        return;
    }
    f_putstr("strnstr passes");
}

void    test_strstr() {
    char *s1 = "thebiggestlittlestring";
    char *s2 = "little";

    assert(f_strcmp(f_strstr(s1, s2), "littlestring") == 0);
    f_putstr("strstr passes");
}

void    test_absval() {
    assert(f_absval(1) == 1);
    assert(f_absval(-1) == 1);
    assert(f_absval(10) == 10);
    assert(f_absval(-10) == 10);
    f_putstr("absval tests passed");
}

int     test_dtoc() {
    assert(f_dtoc(0) == '0');
    assert(f_dtoc(1) == '1');
    assert(f_dtoc(10) == '\0');
    //printf("dtoc tests passed successfully!\n");
    return (0);
}

int     test_isalnum(void) {
    assert(f_isalnum('a') == 1);
    assert(f_isalnum('Z') == 1);
    assert(f_isalnum('5') == 1);
    assert(f_isalnum(' ') == 0);
    printf("isalnum tests passed successfully!\n");
    return (0);
}

int     test_isalpha(void) {
    assert(f_isalpha('a') == 1);
    assert(f_isalpha('b') == 1);
    assert(f_isalpha('5') == 0);
    assert(f_isalpha('z') == 1);
    printf("isalpha tests passed successfully!\n");
    return (0);
}

int     test_isdigit(void) {
    assert(f_isdigit('a') == 0);
    assert(f_isdigit('b') == 0);
    assert(f_isdigit('5') == 1);
    assert(f_isdigit('z') == 0);
    printf("isdigit tests passed successfully!\n");
    return (0);
}

int     test_isascii(void) {
    assert(f_isascii('a') == 1);
    assert(f_isascii('b') == 1);
    assert(f_isascii('5') == 1);
    assert(f_isascii('z') == 1);
    printf("is_ascii tests passed successfully!\n");
    return (0);
}

int     test_is_whitespace(void) {
    assert(f_isascii('a') == 0);
    assert(f_isascii('1') == 0);
    assert(f_isascii(' ') == 1);
    assert(f_isascii('\n') == 1);
    assert(f_isascii('\t') == 1);
    assert(f_isascii('\r') == 1);
    assert(f_isascii('\v') == 1);
    assert(f_isascii('\f') == 1);
    printf("is_ascii tests passed successfully!\n");
    return (0);
}

int     test_isprint(void) {
    assert(f_isprint('a') == 1);
    assert(f_isprint('b') == 1);
    assert(f_isprint('5') == 1);
    assert(f_isprint(' ') == 0);
    assert(f_isprint('\t') == 0);
    assert(f_isprint('\n') == 0);
    printf("is_ascii tests passed successfully!\n");
    return (0);
}

int test_iswhitespace(void) {
    assert(f_iswhitespace('a') == 0);
    assert(f_iswhitespace('b') == 0);
    assert(f_iswhitespace('5') == 0);
    assert(f_iswhitespace(' ') == 1);
    assert(f_iswhitespace('\t') == 1);
    assert(f_iswhitespace('\n') == 1);
    assert(f_iswhitespace('\0') == 0);

    printf("is_whitespace tests passed successfully!\n");
    return (0);
}

int test_strlen(void) {
    assert(f_strlen("") == 0);
    assert(f_strlen("abc") == 3);
    assert(f_strlen("abcabc") == 6);
    assert(f_strlen("abcabcabc") == 9);
    assert(f_strlen("abcabcabcabc") == 12);
    printf("strlen tests passed successfully!\n");
    return (0);
}

int test_putchar(void) {
    f_putchar('t');
    f_putchar('e');
    f_putchar('s');
    f_putchar('t');
    f_putchar('\n');
    printf("putchar tests passed successfully!\n");
    return (0);
}

int test_putstr(char *s) {
    int bytes;
    bytes = f_putstr(s);
    assert(f_strlen(s) == bytes);
    printf("putstr tests passed successfully!\n");
    return (bytes);
}

int test_putendl(char *s) {
    int bytes;
    bytes = f_putendl(s);
    assert(f_strlen(s) + 1 == bytes);
    printf("putendl tests passed successfully!\n");
    return (bytes);
}

void test_strcat () {
    char s1[8] = {
        'a',
        'b',
        'c',
        '\0',
        '\0',
        '\0',
        '\0',
        '\0'
    };
    const char *s2;
    s2 = "123";
    assert(f_strcmp(f_strcat(s1, s2), "abc123") == 0);
    f_putstr("strcat tests past sucessfully\n");
}

void test_strcmp() {
    char    *s1;
    char    *s2;
    
    s1 = "abc";
    s2 = "123";
    assert(f_strcmp(s1, s1) == 0);
    assert(f_strcmp(s1, s2) == -1);
    f_putstr("strcmp tests past sucessfully\n");
}

void test_strncmp() {
    char    *s1;
    char    *s2;
    
    s1 = "abc";
    s2 = "123";
    assert(f_strncmp(s1, s1, 3) == 0);
    assert(f_strncmp(s1, s1, 2) == 0);
    assert(f_strncmp(s1, s2, 3) == -1);
    f_putstr("strncmp tests past sucessfully\n");
}

void test_strcpy() {
    char     s1[5];
    char     *s2;

    s2 = "dcba";
    assert(f_strcmp(f_strcpy(s1, s2), s2) == 0);
    f_putstr("strcpy tests past sucessfully\n");
}

void test_strncpy() {
    char     s1[5];
    char     *s2;

    s2 = "dcba";
    assert(f_strcmp(f_strncpy(s1, s2, 4), s2) == 0);
    f_putstr("strcpy tests past sucessfully\n");
}

void test_strncat() {
    char    s1[5];
    char    *s2;

    s2 = "dcba";
    assert(f_strcmp(f_strncat(s1, s2, 4), s2) == 0);
    f_putstr("strncat tests past successfully");
}

void test_putnbr() {
    f_putnbr(0);
    f_putchar('\n');
    f_putnbr(1);
    f_putchar('\n');
    f_putnbr(10);
    f_putchar('\n');
    f_putnbr(11);
    f_putchar('\n');
    f_putnbr(111);
}

int main(void) {
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_strlen();
    test_putchar();
    test_putstr("test putstr");
    test_putendl("test putendl");
    test_dtoc();
    test_putnbr();
    test_iswhitespace();
    test_strcat();
    test_strcmp();
    test_strncmp();
    test_absval();
    test_strcpy();
    test_strncpy();
    test_strncat();
    test_strnstr();
    test_strsplit();
    return (0);
}