//
//  test_nodes.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/26/22.
//

#include <stdio.h>
#include <check.h>
#include "../common/nodes.h"

START_TEST(nodes_push) {
    node *head = init_node();
    int i = 0;
    head->type = i;
    while (i++ < 14) {
        push(head)->type = i;
    }
    node *read = head;
    i = 0;
    while (read->next) {
        ck_assert_int_eq(i, read->type);
        read = read->next;
        i++;
    }
    clean(head);
} END_TEST

START_TEST(nodes_pop) {
    node *head = init_node();
    int i = 0;
    head->type = i;
    while (i++ < 14) {
        push(head)->type = i;
    }
    node *read = NULL;
    i = 14;
    while (head && i > 0) {
        read = find_last(head);
        ck_assert_int_eq(i, read->type);
        pop(head);
        i--;
    }
    ck_assert_int_eq(i, head->type);
    clean(head);
} END_TEST

START_TEST(nodes_overpop) {
    node *head = init_node();
    int i = 9;
    head->type = i;
    while (i++ < 19) {
        push(head)->type = i;
    }
    node *read = head;
    while (head && i-- > 9) {
        read = find_last(head);
        ck_assert_int_eq(i, read->type);
        pop(head);
    }
    pop(head);
    pop(head);
    pop(head);
    i = 9;
    ck_assert_int_eq(i, head->type);
    clean(head);
} END_TEST

START_TEST(nodes_clean) {
    node *head = init_node();
    head = clean(head);
    clean(head);
    ck_assert_ptr_eq(NULL, head);
} END_TEST

int main(void) {
    Suite *suite_nodes = suite_create("Nodes");
    TCase *tc1 = tcase_create("Core");
    SRunner *sr = srunner_create(suite_nodes);
    int nf;

    suite_add_tcase(suite_nodes, tc1);
    tcase_add_test(tc1, nodes_push);
    tcase_add_test(tc1, nodes_pop);
    tcase_add_test(tc1, nodes_overpop);
    tcase_add_test(tc1, nodes_clean);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
