% 만든 사람 : 이경훈
% blog : http://blog.naver.com/angel4six

% X는 입력 matrix, y는 결과 matrix
function theta = gradient(X,y)
[m, n] = size(X) % m은 트레이닝 숫자, n은 features 개수
n=n-1;
alpha = 0.000001;
theta = zeros(1,n+1);

in = ones(n+1,1)    % (n+1) x 1 vector 생성
for i=2:n+1
    in(i,1) = input('input:')
end

% cost functino 과 gradient descent
for i=1:10000
    u = zeros(1,m);
    u = (h(X,theta) - y)';
    delta =(1/m)* u*X;
    theta = theta - alpha*delta;
end;
disp('predicted value below : ')
theta = theta*in
    
end;
