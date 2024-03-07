Program Timkiem_nhiphan;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
    x:integer;
procedure nhap(var a:mang; var n:byte; var x:integer);
var i:byte;
begin
  write('Nhap n: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
  write('Nhap x: ');readln(x);
end;
function timkiem(a:mang; dau,cuoi:byte; x:integer):boolean;
var giua:byte;
begin
  while (dau<=cuoi) do
    begin
      giua:=(dau+cuoi) div 2;
      if (a[giua]=x) then
        exit(true);
      if (a[giua]<x) then
        dau:=giua+1
      else
        cuoi:=giua-1;
    end;
  exit(false);
end;
procedure xuly(a:mang; n:byte; x:integer);
begin
  if (timkiem(a,1,n,x)) then
    write('CO')
  else
    write('KHONG');
end;
Begin
  clrscr;
  nhap(a,n,x);
  xuly(a,n,x);
  readln
End.