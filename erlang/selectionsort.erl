-module(selection-sort).
-export([ssort/1]).

%% Naive implementation.
ssort([]) ->
        [];
ssort(List) ->
        M = min(List),
        [M | ssort(delete(M,List))].
