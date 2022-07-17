-module(mergesort).
-export([naive/1,efficient/1]).

merge([],B) ->
        B;
merge(A,[]) ->
        A;
merge(A,B) ->
        [AHead|ATail] = A,
        [BHead|BTail] = B,
        case AHead =< BHead of
                true ->
                        [AHead|merge(ATail,B)];
                false ->
                        [BHead|merge(A,BTail)]
        end.

%% Naive implementation.
naive([]) ->
        [];
naive([Element]) ->
        [Element];
naive(List) ->
        {Begining,End} = lists:split(round(math:floor(length(List)/2)),List),
        merge(naive(Begining),naive(End)).

%% Efficient implementation.
split([]) ->
        [];
split([Head|Tail]) ->
        [[Head]|split(Tail)].

mergepairs([]) ->
        [];
mergepairs([Element]) ->
        [Element];
mergepairs([First|[Second|Tail]]) ->
        [merge(First,Second)|mergepairs(Tail)].

efficient(List) ->
        MS = fun Rec([Element]) ->
                             Element;
                 Rec(InnerList) ->
                             Rec(mergepairs(InnerList))
             end,
        MS(split(List)).
