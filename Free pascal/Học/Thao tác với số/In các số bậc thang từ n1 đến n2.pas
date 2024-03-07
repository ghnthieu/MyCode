Program bai3;
uses crt;
var n1,n2:longint;
procedure nhap(var n1,n2:longint);
begin
  write('Nhap so N1: ');readln(n1);
  write('Nhap so N2: ');readln(n2);
end;
function kt(n:longint):boolean;
var ok:boolean;
    i:byte;
    s:string;
begin
  ok:=true;
  if n<10 then
    ok:=false;
  str(n,s);
  for i:=1 to length(s)-1 do
    if s[i]>s[i+1] then
      begin
        ok:=false;
        break;
      end;
  kt:=ok;
end;
procedure in_ra(n1,n2:longint);
var i:longint;
begin
  writeln('So bac thang la: ');
  for i:=n1 to n2 do
    if kt(i) then
      write(i,' ');
end;
Begin
  clrscr;
  nhap(n1,n2);
  in_ra(n1,n2);
  readln
End.
