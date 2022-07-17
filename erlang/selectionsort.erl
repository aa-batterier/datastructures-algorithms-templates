-module(selectionsort).
-export([naive/1,efficient/1]).

%% Naive implementation.
naive([]) ->
        [];
naive(List) ->
        M = lists:min(List),
        [M|naive(lists:delete(M,List))].

%% Efficient implementation.
split([],Minimum,Rest) ->
        [Minimum|efficient(Rest)];
split([Head|Tail],Minimum,Rest) ->
        case Head < Minimum of
                true ->
                        split(Tail,Head,[Minimum|Rest]);
                false ->
                        split(Tail,Minimum,[Head|Rest])
        end.

efficient([]) ->
        [];
efficient([Head|Tail]) ->
        split(Tail,Head,[]).
