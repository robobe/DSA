#include <iostream>
#include <gtest/gtest.h>

#include <LinkList.hpp>

typedef LinkList* LinkListPtr;

TEST(LinkList, basic)
{
    LinkListPtr ll = new LinkList();
    ll->Append(5);
    ll->Append(1);
    ll->Append(10);
    ll->Traverse();
    auto index = ll->Find(10);
    std::cout << "index " << index << std::endl;
    ASSERT_TRUE(index == 2);
}

class LinkListTest : public testing::Test
{
    protected:
    void SetUp() override
    {
        ll->Append(5);
        ll->Append(1);
        ll->Append(10);
    }

    LinkListPtr ll = new LinkList();

};

TEST_F(LinkListTest, FindTests){
    ASSERT_TRUE(ll->Find(1) == 1);
}

TEST_F(LinkListTest, FindTestsUpperLimits){
    int result = ll->Find(11);
    ASSERT_TRUE(result == -1);
}

TEST_F(LinkListTest, EmptyList){
    auto ll = new LinkList();
    int result = ll->Find(11);
    ASSERT_TRUE(result == -1);
}