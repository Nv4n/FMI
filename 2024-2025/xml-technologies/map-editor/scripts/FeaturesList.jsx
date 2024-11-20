import { List, Typography } from '@mui/material';

import FeatureListItem from '@scripts/FeatureListItem';

export default function FeaturesList({features, onDelete}) {
    if (features.length < 1) {
        return (
            <Typography sx={(theme) => ({textAlign: 'center', paddingTop: theme.spacing(4)})}>
                Няма добавени обекти
            </Typography>
        );
    }

    const listItems = features.map((feature) =>
        <FeatureListItem
            key={feature.getId()}
            feature={feature}
            onDelete={() => onDelete(feature)}
        />
    );

    return (
        <List>
            {listItems}
        </List>
    );
}
