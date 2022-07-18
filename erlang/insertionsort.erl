-module(insertionsort).
-export([naive/1,efficient/1,betterEfficient/1]).

%% Naive implementation.
naiveInsert(Head,Tail) ->
        [X || X <- Tail, Head > X] ++ [Head] ++ [X || X <- Tail, Head =< X].

naive([]) ->
        [];
naive([Head|Tail]) ->
        naiveInsert(Head,naive(Tail)).

%% Efficient implementation with naive insert.
efficient(List) ->
        lists:foldr(fun(Key,InnerList) -> naiveInsert(Key,InnerList) end,[],List).

%% Efficient implementation.
efficientInsert(Key,[]) ->
        [Key];
efficientInsert(Key,[Head|Tail] = List) ->
        case Key =< Head of
                true ->
                        [Key|List];
                false ->
                        [Head|efficientInsert(Key,Tail)]
        end.

betterEfficient(List) ->
        lists:foldr(fun(Key,InnerList) -> efficientInsert(Key,InnerList) end,[],List).
