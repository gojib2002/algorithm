class Solution {
  public int solution(int n) {
      int prev = 1;
      int next = 1;
      int tmp;
      
      for (int i=0; i<n-1; i++) {
          tmp = next;
          next = (prev + next)%1000000007;
          prev = tmp;
      }
      
      return next;
  }
}
