Program bai1;
uses crt;
var n:integer;
procedure nhap(var n:integer);
begin
  write('N=');readln(n);
end;
function kt(n:integer):boolean;
var i,stn:integer;
    ok:boolean;
begin
  stn:=0;
  for i:=1 to n div 2 do
    if n mod i=0 then
      stn:=stn+i;
  if stn=n then
    ok:=true
  else
    ok:=false;
  kt:=ok;
end;
procedure xuly(n:integer);
var i:integer;
begin
  if kt(n) then
    write(n,' La so hoan hao')
  else
    write(n,' Khong phai la so hoan hao');
end;
Begin
  clrscr;
  nhap(n);
  xuly(n);
  readln
End.
