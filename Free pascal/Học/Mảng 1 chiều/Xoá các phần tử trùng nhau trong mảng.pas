Uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
procedure nhap(var a:mang; var n:byte);
var i:byte;
begin
  write('Nhap do dai phan tu: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure inra(a:mang; n:byte);
var i,j,k:byte;
begin
  i:=2;                         
  while i<=n do
    begin
      j:=1;
      while a[j]<>a[i] do
        inc(j);
      if j<i then
        begin
          for k:=i to n-1 do
            a[k]:=a[k+1];
          dec(n);
        end
      else
        inc(i);
    end;
  for i:=1 to n do
    write(a[i],' ');
end;
Begin
  clrscr;
  nhap(a,n);
  inra(a,n);
  readln
End.