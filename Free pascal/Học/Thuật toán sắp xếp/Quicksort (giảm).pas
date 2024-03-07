Program Quick_sort;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
procedure nhap(var a:mang; var n:byte);
var i:byte;
begin
  write('Nhap n: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure doicho(var a,b:integer);
var t:integer;
begin
  t:=a;
  a:=b;
  b:=t;
end;
procedure sort(var a:mang; l,r:byte);
var i,j,chot:byte;
begin
  if (l>=r) then
    exit;
  i:=l;
  j:=r;
  chot:=a[(l+r) div 2];
  repeat
    while (a[i]>chot) do
      inc(i);
    while (a[j]<chot) do
      dec(j);
    if (i<=j) then
      begin
        if (i<j) then
          doicho(a[i],a[j]);
        inc(i);
        dec(j);
      end;
  until (i>j);
  sort(a,l,j);
  sort(a,i,r);
end;
procedure xuly(a:mang; n:byte);
var i:byte;
begin
  sort(a,1,n);
  for i:=1 to n do
    write(a[i],' ');
end;
Begin
  clrscr;
  nhap(a,n);
  xuly(a,n);
  readln
End.