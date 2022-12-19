#include "map"
#include "set"
#include <iostream>
#include "cassert"
#include "exception"
#include "sstream"

#define ���� {
#define ��� }
#define ����� ;
#define �������� cout<<
#define ������ cin>>
#define � <<
#define ����� void
#define ���� bool
#define ����� int
#define ������ template
#define ��� using
#define ���� namespace
#define ���� std
#define ����� main()
#define ���� if
#define ���� else
#define �� (
#define �� )
#define ��� !
#define �� ==
#define ����� return
#define ������� 1
#define ����� 0
#define ������_���� while
#define ��� =
#define ��������� public
#define ���������� private
#define ��_����� try
#define ����_���� catch
#define ������ exit
#define ������ throw

��� ���� ���� �����
��� syn = map<string, set<string>>;

//����������� �������
����� addsynonims �� map<string, set<string>>& synonims, const string first_word, const string second_word �� ����
    synonims[second_word].insert(first_word) �����
    synonims[first_word].insert(second_word) �����
���

size_t getsyncount �� map<string, set<string>>& synonims, const string word �� ����
    ����� synonims[word].size() �����
���

���� aresynonims �� map<string, set<string>>& synonims, const string first_word, const string second_word �� ����
    ����� synonims[first_word].count(second_word) �����
���

����� sum �� int x, int y ��  ����
    ����� x + y �����
���

//�������� �������
������ <class T, class U>
����� AssertEqual �� const T& t, const U& u, int hint �� ����
    ���� �� t != u �� ����
        ostringstream os;
        os � "assertion failed: " � "Line: " � hint �����
        ������ runtime_error �� os.str �� �� �� �����
    ���
���

����� Assert �� ���� b, ���� hint �� ����
    AssertEqual �� b, true, hint �� �����
���
����� test_sum() ����
    AssertEqual(sum(2, 3), 5, 39) �����
    AssertEqual(sum(-2, -3), -5, 40) �����
    AssertEqual(sum(-2, 0), -2, 41) �����
    AssertEqual(sum(2, -2), 0, 42) �����
    �������� "test sum ok" � endl �����
���
����� test_addsynonims() ����
    ����
        syn empty �����
        addsynonims(empty, "a", "b") �����
        const syn expected ��� ����
            {"a",{"b"}},
            {"b",{"a"}},
        ��� �����
        AssertEqual(empty, expected, 50) �����

    ���
    ����
        syn synn ��� ����
            {"a",{"b"}},
            {"c",{"b"}},
            {"b",{"a","c"}},
        ��� �����
        addsynonims(synn, "a", "c") �����
        syn expected ��� {
            {"a",{"b","c"}},
            {"c",{"b","a"}},
            {"b",{"a","c"}},
        ��� �����
        AssertEqual(synn, expected, 64) �����
        �������� "test addsynonims ok" � endl �����
    ���
���
����� test_getsyncount() ����
    ����
        ����
            syn empty �����
            AssertEqual(getsyncount(empty, "a"), 0u, 72) �����
        ���
        ����
            syn synn ��� ����
            {"a",{"b","c"}},
            {"b",{"a"}},
            {"c",{"a"}},
            ��� �����
            AssertEqual(getsyncount(synn, "a"), 2u, 80) �����
            AssertEqual(getsyncount(synn, "b"), 1u, 81) �����
            AssertEqual(getsyncount(synn, "z"), 0u, 82) �����
        ���
        �������� "get synonims count ok" � endl �����
    ���
���
����� test_aresynonims() ����
    ����
        syn empty;
        assert(!aresynonims(empty, "a", "b")) �����
        assert(!aresynonims(empty, "b", "a")) �����
    ���
    ����
        syn synn ��� ����
            {"a",{"b","c"}},
            {"b",{"a"}},
            {"c",{"a"}},
        ��� �����
        assert(aresynonims(synn, "a", "b")) �����
        assert(aresynonims(synn, "b", "a")) �����
        assert(aresynonims(synn, "a", "c")) �����
        assert(aresynonims(synn, "c", "a")) �����
        assert(!aresynonims(synn, "c", "b")) �����
        assert(!aresynonims(synn, "b", "c")) �����
    ���
    �������� "are synonims ok" � endl �����
���

class testrunner ����
���������:
    template <class testfunk>
    ����� runtest �� testfunk func, string testname �� ����
        ��_����� ���� func() ����� ���
        ����_���� �� runtime_error& e �� ����
            �������� testname � " error: " � e.what() � endl �����
            ++fail_count �����
        ���
    ���
    ~testrunner() ����
        ���� �� fail_count > ����� �� ����
            �������� fail_count � " tests failed. terminating process" � endl �����
            ������ �� ������� �� �����
        ���
    ���
����������:
    ����� fail_count ��� ����� �����

��� �����

����� testall() ����
    testrunner tr �����
    tr.runtest �� test_sum, "test_sum" �� �����
    tr.runtest �� test_addsynonims, "test_addsynonims" �� �����
    tr.runtest �� test_getsyncount, "test_getsyncount" �� �����
    tr.runtest �� test_aresynonims, "test_aresynonims" �� �����
���

����� main_func() ����
    string operator_code �����
    map<string, set<string>> synonims �����
    ���� work ��� true �����
    ������_���� �� work �� ����
        �������� "enter operator (add/check/count/exit)" << endl �����
        ������ operator_code �����
        ���� �� operator_code �� "add" �� ����
            string f_word, sec_word �����
            �������� "enter two new synonims" << endl �����
            ������ f_word >> sec_word �����
            addsynonims �� synonims, f_word, sec_word �� �����
        ���
        ���� ���� �� operator_code �� "count" �� ����
            string word �����
            �������� "enter word" � endl �����
            ������ word �����
            �������� getsyncount �� synonims, word �� � endl �����
        ���
        ���� ���� �� operator_code �� "exit" �� ����
            exit �� 1 �� �����
        ���
        ���� ���� �� operator_code �� "check" �� ����
            string f_word, sec_word �����
            �������� "enter words u want to check" � endl �����
            ������ f_word >> sec_word �����
            ���� �� aresynonims �� synonims, f_word, sec_word �� �� 1 ��
                �������� "yes" � endl �����
            else
                �������� "no" � endl �����

        ���
    ���
���


����� �����
����
    ����� mode �����
    �������� "select mode(0-only_main/1-video_mode/2-only_test)" � endl �����
    ������ mode �����
    ���� �� mode �� ����� �� ����
        main_func ��) �����
    ���
    ���� ���� �� mode �� ������� �� ����
        testall ��) �����
        main_func ��) �����
    ���
    ���� ����
        try ����
            testall ��)�����
        ���
        catch �� runtime_error& e �� ����
            �������� "error: " � e.what() � endl �����
        ���
    ���
    ����� ����� �����
���