Program mang1c;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
    k:integer;
procedure nhap(var a:mang; var k:integer; var n:byte);
var i:byte;
begin
  write('N=');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
  write('K=');readln(k);
end;
procedure xuat(a:mang; k:integer; n:byte);
var i,dem:byte;
begin
  dem:=0;
  write('Vi tri cua ',k,' trong mang: ');
  for i:=1 to n do
    if k=a[i] then
      begin
        write(i,' ');
        inc(dem);
      end;
  if dem=0 then
    write('Khong co');
end;
Begin
  clrscr;
  nhap(a,n,k);
  xuat(a,n,k);
  readln
End.