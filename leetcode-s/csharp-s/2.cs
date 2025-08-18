/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:54:26
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode neo = new ListNode();
        ListNode ans = neo;
        ListNode p1 = l1, p2 = l2;
        int remain = 0;

        while (p1 != null || p2 != null || remain != 0)
        {
            int sum = remain;

            if (p1 != null)
            {
                sum += p1.val;
                p1 = p1.next;
            }

            if (p2 != null)
            {
                sum += p2.val;
                p2 = p2.next;
            }

            remain = sum / 10;
            ans.val += sum % 10;

            if (p1 != null || p2 != null || remain != 0)
            {
                ans.next = new ListNode();
                ans = ans.next;
            }
        }

        return neo;
    }
}