Program day_con;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
procedure nhap(var a:mang; var n:byte);
var i:byte;
begin
  write('Nhap do dai cua day: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure in_ra(a:mang; n:byte);
var i:byte;
begin
  writeln('Mang vua nhap la: ');
  for i:=1 to n do
    write(a[i],' ');
  writeln;
end;
function tong_dc(a:mang; i,j:integer):integer;
var tong,k:integer;
begin
  tong:=0;
  for k:=i to i+j do
    tong:=tong+a[k];
  tong_dc:=tong;
end;
procedure dc_tong(a:mang; n:integer);
var i,j,max,csdau,dai,dem:integer;
begin
  max:=a[1];
  i:=1;
  for j:=0 to n-i+1 do
    if tong_dc(a,i,j)>max then
      begin
        max:=tong_dc(a,i,j);
        csdau:=i;
        dai:=j;
      end;
  inc(dai);
  writeln(max,' ',csdau,' ',dai);
end;
Begin
  clrscr;
  nhap(a,n);
  in_ra(a,n);
  dc_tong(a,n);
  readln
End.