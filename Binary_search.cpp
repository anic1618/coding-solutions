print first element <= to item
while(beg<end){
  mid = (beg+end)>>1;
  if(A[mid]<item) beg = mid+1;
  else end = mid;//end keep solution(atleast it can be print)
}
return end;
