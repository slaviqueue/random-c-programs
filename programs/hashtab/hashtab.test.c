#include "hashtab/hashtab.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(hashtab, a_simple_hash_table) {
  Hashtab tab = hashtab_make();

  cr_expect_eq(hashtab_set(&tab, "name", "billy"), true);
  cr_expect_eq(hashtab_set(&tab, "surname", "herrington"), true);

  cr_expect_str_eq(hashtab_get(&tab, "surname"), "herrington");
  cr_expect_str_eq(hashtab_get(&tab, "name"), "billy");

  hashtab_free(&tab);
}

Test(hashtab, setting_a_key_multiple_times_overrides_the_value) {
  Hashtab tab = hashtab_make();

  cr_expect_eq(hashtab_set(&tab, "name", "billy"), true);
  cr_expect_eq(hashtab_set(&tab, "name", "not-billy"), true);

  cr_expect_str_eq(hashtab_get(&tab, "name"), "not-billy");

  hashtab_free(&tab);
}

Test(hashtab, can_delete_by_key) {
  Hashtab tab = hashtab_make();

  hashtab_set(&tab, "name", "billy");
  hashtab_unset(&tab, "name");

  cr_expect_eq(hashtab_get(&tab, "name"), NULL);

  hashtab_free(&tab);
}

Test(hashtab, does_not_crash_when_unsetting_a_key_that_does_not_exist) {
  Hashtab tab = hashtab_make();

  hashtab_unset(&tab, "name");
  cr_expect_eq(hashtab_get(&tab, "name"), NULL);

  hashtab_free(&tab);
}
