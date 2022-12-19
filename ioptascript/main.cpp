#include "map"
#include "set"
#include <iostream>
#include "cassert"
#include "exception"
#include "sstream"

#define типа {
#define еба }
#define блять ;
#define спиздани cout<<
#define спроси cin>>
#define и <<
#define нихуя void
#define факт bool
#define хуета int
#define черкаш template
#define иди using
#define сюда namespace
#define сука std
#define стопе main()
#define если if
#define хуле else
#define да (
#define то )
#define хуй !
#define ты ==
#define отдал return
#define пиздато 1
#define хуево 0
#define пиздуй_пока while
#define это =
#define советский public
#define пендосский private
#define ну_давай try
#define стой_сука catch
#define пиздуй exit
#define вкинул throw

иди сюда сука блять
иди syn = map<string, set<string>>;

//тестируемые функции
нихуя addsynonims да map<string, set<string>>& synonims, const string first_word, const string second_word то типа
    synonims[second_word].insert(first_word) блять
    synonims[first_word].insert(second_word) блять
еба

size_t getsyncount да map<string, set<string>>& synonims, const string word то типа
    отдал synonims[word].size() блять
еба

факт aresynonims да map<string, set<string>>& synonims, const string first_word, const string second_word то типа
    отдал synonims[first_word].count(second_word) блять
еба

хуета sum да int x, int y то  типа
    отдал x + y блять
еба

//тестовые функции
черкаш <class T, class U>
нихуя AssertEqual да const T& t, const U& u, int hint то типа
    если да t != u то типа
        ostringstream os;
        os и "assertion failed: " и "Line: " и hint блять
        вкинул runtime_error да os.str да то то блять
    еба
еба

нихуя Assert да факт b, факт hint то типа
    AssertEqual да b, true, hint то блять
еба
нихуя test_sum() типа
    AssertEqual(sum(2, 3), 5, 39) блять
    AssertEqual(sum(-2, -3), -5, 40) блять
    AssertEqual(sum(-2, 0), -2, 41) блять
    AssertEqual(sum(2, -2), 0, 42) блять
    спиздани "test sum ok" и endl блять
еба
нихуя test_addsynonims() типа
    типа
        syn empty блять
        addsynonims(empty, "a", "b") блять
        const syn expected это типа
            {"a",{"b"}},
            {"b",{"a"}},
        еба блять
        AssertEqual(empty, expected, 50) блять

    еба
    типа
        syn synn это типа
            {"a",{"b"}},
            {"c",{"b"}},
            {"b",{"a","c"}},
        еба блять
        addsynonims(synn, "a", "c") блять
        syn expected это {
            {"a",{"b","c"}},
            {"c",{"b","a"}},
            {"b",{"a","c"}},
        еба блять
        AssertEqual(synn, expected, 64) блять
        спиздани "test addsynonims ok" и endl блять
    еба
еба
нихуя test_getsyncount() типа
    типа
        типа
            syn empty блять
            AssertEqual(getsyncount(empty, "a"), 0u, 72) блять
        еба
        типа
            syn synn это типа
            {"a",{"b","c"}},
            {"b",{"a"}},
            {"c",{"a"}},
            еба блять
            AssertEqual(getsyncount(synn, "a"), 2u, 80) блять
            AssertEqual(getsyncount(synn, "b"), 1u, 81) блять
            AssertEqual(getsyncount(synn, "z"), 0u, 82) блять
        еба
        спиздани "get synonims count ok" и endl блять
    еба
еба
нихуя test_aresynonims() типа
    типа
        syn empty;
        assert(!aresynonims(empty, "a", "b")) блять
        assert(!aresynonims(empty, "b", "a")) блять
    еба
    типа
        syn synn это типа
            {"a",{"b","c"}},
            {"b",{"a"}},
            {"c",{"a"}},
        еба блять
        assert(aresynonims(synn, "a", "b")) блять
        assert(aresynonims(synn, "b", "a")) блять
        assert(aresynonims(synn, "a", "c")) блять
        assert(aresynonims(synn, "c", "a")) блять
        assert(!aresynonims(synn, "c", "b")) блять
        assert(!aresynonims(synn, "b", "c")) блять
    еба
    спиздани "are synonims ok" и endl блять
еба

class testrunner типа
советский:
    template <class testfunk>
    нихуя runtest да testfunk func, string testname то типа
        ну_давай типа func() блять еба
        стой_сука да runtime_error& e то типа
            спиздани testname и " error: " и e.what() и endl блять
            ++fail_count блять
        еба
    еба
    ~testrunner() типа
        если да fail_count > хуево то типа
            спиздани fail_count и " tests failed. terminating process" и endl блять
            пиздуй да пиздато то блять
        еба
    еба
пендосский:
    хуета fail_count это хуево блять

еба блять

нихуя testall() типа
    testrunner tr блять
    tr.runtest да test_sum, "test_sum" то блять
    tr.runtest да test_addsynonims, "test_addsynonims" то блять
    tr.runtest да test_getsyncount, "test_getsyncount" то блять
    tr.runtest да test_aresynonims, "test_aresynonims" то блять
еба

нихуя main_func() типа
    string operator_code блять
    map<string, set<string>> synonims блять
    факт work это true блять
    пиздуй_пока да work то типа
        спиздани "enter operator (add/check/count/exit)" << endl блять
        спроси operator_code блять
        если да operator_code ты "add" то типа
            string f_word, sec_word блять
            спиздани "enter two new synonims" << endl блять
            спроси f_word >> sec_word блять
            addsynonims да synonims, f_word, sec_word то блять
        еба
        хуле если да operator_code ты "count" то типа
            string word блять
            спиздани "enter word" и endl блять
            спроси word блять
            спиздани getsyncount да synonims, word то и endl блять
        еба
        хуле если да operator_code ты "exit" то типа
            exit да 1 то блять
        еба
        хуле если да operator_code ты "check" то типа
            string f_word, sec_word блять
            спиздани "enter words u want to check" и endl блять
            спроси f_word >> sec_word блять
            если да aresynonims да synonims, f_word, sec_word то ты 1 то
                спиздани "yes" и endl блять
            else
                спиздани "no" и endl блять

        еба
    еба
еба


хуета стопе
типа
    хуета mode блять
    спиздани "select mode(0-only_main/1-video_mode/2-only_test)" и endl блять
    спроси mode блять
    если да mode ты хуево то типа
        main_func да) блять
    еба
    хуле если да mode ты пиздато то типа
        testall да) блять
        main_func да) блять
    еба
    хуле типа
        try типа
            testall да)блять
        еба
        catch да runtime_error& e то типа
            спиздани "error: " и e.what() и endl блять
        еба
    еба
    отдал хуево блять
еба