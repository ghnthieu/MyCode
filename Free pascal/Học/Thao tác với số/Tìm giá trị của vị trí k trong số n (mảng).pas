Program bai2;
uses crt;
type mang=array[1..100] of byte;
var n:qword;
    k:byte;
procedure nhap(var n:qword; var k:byte);
begin
  write('Nhap so N: ');readln(n);
  write('Nhap so K: ');readln(k);
end;
procedure in_ra(n:qword;k:byte);
var dem,i:byte;
    t:qword;
    a:mang;
begin
  dem:=0;
  t:=n;
  while n<>0 do
    begin
      i:= n mod 10;
      n:= n div 10;
      inc(dem);
      a[dem]:=i;
    end;
  if (k>dem) or (k<=0) then
    writeln('-1')
  else
    write('Vi tri cua ',k,' trong ',t,' la: ',a[dem-k+1]);
end;
Begin
  clrscr;
  nhap(n,k);
  in_ra(n,k);
  readln
End.