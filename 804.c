#include <stdlib.h>

int uniqueMorseRepresentations(char **words, int wordsSize) {
    char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
                     "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    for (int i = 0; i < wordsSize - 1; i++) {
        char *p1 = words[i];
        if (p1 && *p1) {
            for (int j = i + 1; j < wordsSize; j++) {
                char *p1 = words[i];
                char *p2 = words[j];
                if (p2 && *p2) {
                    char *m1 = morse[*p1 - 'a'];
                    char *m2 = morse[*p2 - 'a'];
                    while (m1 && m2 && *m1 && *m2) {
                        if (*m1 != *m2) {
                            break;
                        }
                        m1++;
                        m2++;
                        if (*m1 == 0) {
                            p1++;
                            if (*p1) {
                                m1 = morse[*p1 - 'a'];
                            } else {
                                m1 = 0;
                            }
                        }
                        if (*m2 == 0) {
                            p2++;
                            if (*p2) {
                                m2 = morse[*p2 - 'a'];
                            } else {
                                m2 = 0;
                            }
                        }
                    }
                    if (m1 || m2) {
                        continue;
                    }
                    words[j] = 0;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (words[i]) {
            count++;
        }
    }
    return count;

}

int main() {
    char *words[] = {
            "gin", "zen", "gig", "msg"
    };

    int k = uniqueMorseRepresentations(words, 4);

    return 0;
}