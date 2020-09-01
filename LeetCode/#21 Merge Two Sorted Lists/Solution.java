import java.util.List;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode answer = new ListNode();
        ListNode curr = answer;

        while (l1 != null || l2 != null) {
            ListNode tmp = new ListNode();
            if (l1 == null) {
                tmp.val = l2.val;
                l2 = l2.next;
            } else if (l2 == null) {
                tmp.val = l1.val;
                l1 = l1.next;
            } else if (l1.val <= l2.val) {
                tmp.val = l1.val;
                l1 = l1.next;
            } else {
                tmp.val = l2.val;
                l2 = l2.next;
            }
            curr.next = tmp;
            curr = tmp;
        }
        return answer.next;
    }
}