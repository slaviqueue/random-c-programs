int strindexr(char* s, char* t) {
  int match = -1;

  for (int i = 0; s[i] != '\0'; i++) {
    int j = 0;

    for (; s[i + j] != '\0' && t[j] != '\0' && s[i + j] == t[j]; j++)
      ;

    if (j > 0 && t[j] == '\0')
      match = i;
  }

  return match;
}
