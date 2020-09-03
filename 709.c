char* toLowerCase(char* str) {
    char *p = str;
    while(*p) {
        if (*p >= 'A' && *p <= 'Z') {
            *p = *p - 'A' + 'a';
        }
        p++;
    }
    return str;
}