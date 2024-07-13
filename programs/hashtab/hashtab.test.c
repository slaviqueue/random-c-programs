#include "hashtab/hashtab.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(hashtab, a_simple_hash_table) {
  Hashtab tab = hashtab_make();

  hashtab_set(&tab, "name", "billy");
  hashtab_set(&tab, "surname", "herrington");

  cr_expect_str_eq(hashtab_get(&tab, "surname"), "herrington");
  cr_expect_str_eq(hashtab_get(&tab, "name"), "billy");

  hashtab_free(&tab);
}
