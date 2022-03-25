-- ����������д��˼·����ȷ��, ����Ǵ����, ��Ϊmin(event_date)��device_id�޹�, device_id��ȡ��һ������
-- SELECT
--     player_id, device_id
-- FROM 
--     (
--         SELECT 
--             player_id, device_id, min(event_date)
--         FROM
--             Activity
--         GROUP BY
--             player_id
--     ) AS temp

SELECT
    player_id, device_id
FROM
    Activity as a1
WHERE
    (a1.player_id, a1.event_date) IN
    ( 
        SELECT
            player_id, min(event_date) as event_date
        FROM
            Activity as a2
        GROUP BY
            player_id
    )